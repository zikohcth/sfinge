#include "FinGe.h"
#include <iostream>
FinGe::FinGe(void)
{
	minF = 1.0/15;
	maxF = 1.0/5;
	mode = FG_MODE_DEBUG;
	nCore = 0;
	nDelta = 0;
	cores = NULL;
	deltas = NULL;
}


FinGe::~FinGe(void)
{
}

void FinGe::set_shape( int left, int right, int top, int bottom, int middle )
{
	sL = left;
	sR = right;
	sT = top;
	sB = bottom;
	sM = middle;
	size = Size(sL+sR, sT+sM+sB);
	generate_shape();
}

void FinGe::generate_shape()
{
	shape = Mat::zeros(size, CV_64FC1);
	ellipse(shape, Point(sL,sT), Size(sL,sT), 0, 180, 270, 1, -1);
	ellipse(shape, Point(sL-1,sT), Size(sR,sT), 0, 270, 360, 1, -1);
	ellipse(shape, Point(sL,sT+sM-1), Size(sL,sB), 0, 90, 180, 1, -1);
	ellipse(shape, Point(sL-1,sT+sM-1), Size(sR,sB), 0, 0, 90, 1, -1);
	rectangle(shape, Rect(0,sT, sL+sR, sM), 1, -1);
	if (mode==FG_MODE_DEBUG) {
		show_shape();
		std::cout<<"Step 1: Generate shape\nPress any key to go to Step 2 ...\n";
		waitKey(0);
	}
	generate_density();
}

void FinGe::show_shape()
{
	imshow("Finger shape", shape);
}

void FinGe::generate_density()
{
	int resolution[] = {5, 6, 7};
	int padding =10;
	RNG rng(time(NULL));    //random seed base on current time
	density = Mat::zeros(size, CV_64FC1);
	density_steps = Mat::zeros(size.height+padding*2, size.width*3+padding*4, CV_64FC1);
	std::cout<<"Step2: Density map (Frequency map)\n";
	for (int i=0; i<3; i++) {
		Mat zoom_img(resolution[i], resolution[i], CV_64FC1);
		rng.fill(zoom_img, RNG::UNIFORM, minF, maxF);	//generate noise image with zoom
		resize(zoom_img, zoom_img, size, 0, 0, INTER_CUBIC);
		density += zoom_img/3.0;
		zoom_img.copyTo(density_steps(Rect(i*size.width+(i+1)*padding,padding,size.width,size.height)));
		if (mode==FG_MODE_DEBUG) {
			imshow("Density", density_steps);
			std::cout<<"Density layer "<<i+1<<"\nPress any key to continue...\n";
			waitKey(0);
		}
	}
	if (mode==FG_MODE_DEBUG) {
		show_density();
		std::cout<<"Press any key to go to Step 3\n";
		waitKey(0);
	}
}

void FinGe::set_ridge_width( int min_width, int max_width )
{
	minF = 1.0/max_width;
	maxF = 1.0/min_width;
	generate_density();
}

void FinGe::show_density()
{
	imshow("Density", density);
}

void FinGe::set_mode( int mode/*=FG_MODE_DEBUG*/ )
{
	this->mode = mode;
}

void FinGe::set_points( int nCore, Point2d* cores, int nDelta, Point2d* deltas )
{
	this->nCore = nCore;
	this->nDelta = nDelta;

	if (this->cores) {
		delete[] this->cores;
		this->cores = NULL;
	}
	if (nCore) {
		this->cores = new Point2d[nCore];
		for (int i=0;i<nCore;i++) this->cores[i] = cores[i];
	}

	if (this->deltas) {
		delete[] this->deltas;
		this->deltas = NULL;
	}

	if (nDelta) {
		this->deltas = new Point2d[nDelta];
		for (int i=0;i<nDelta;i++) this->deltas[i] = deltas[i];
	}

	generate_orientation();
}

void FinGe::generate_orientation()
{
	orientation = Mat::zeros(size, CV_64FC1);
	for (int i=0; i<size.width; i++) {
		for (int j=0; j<size.height; j++) {
			double theta=0;
			for (int k=0; k<nCore; k++) {
				Vec2d z = cores[k]-Point2d(i,j);
				theta += atan2(z[1],z[0]);
			}
			for (int k=0; k<nDelta; k++) {
				Vec2d z = deltas[k]-Point2d(i,j);
				theta -= atan2(z[1],z[0]);
			}
			theta *= 0.5;
			orientation.at<double>(j,i) = theta;
		}
	}

	orientation_display = Mat::zeros(size, CV_64FC1);
	for (int i=5; i<size.width; i+=10)
		for (int j=5; j<size.height; j+=10) {
			Point center(i,j);
			double theta = orientation.at<double>(j,i);
			Point2d p1(i-4.5*cos(theta), j-4.5*sin(theta));
			Point2d p2(i+4.5*cos(theta), j+4.5*sin(theta));
			line(orientation_display, p1, p2, 1);
		}
	orientation_display = orientation_display.mul(shape);
	Mat m_[] = {orientation_display,orientation_display,orientation_display};
	merge(m_, 3 ,orientation_display);
	for (int k=0; k<nCore; k++) {
		circle(orientation_display, cores[k], 5, Scalar(0,0,1) , 1);
	}
	for (int k=0; k<nDelta; k++) {
		circle(orientation_display, deltas[k], 5, Scalar(0,1,0) , 1);
	}

	if (mode==FG_MODE_DEBUG) {
		show_orientation();
		std::cout<<"Press any key to go to step 4\n";
		waitKey(0);
	}

	generate_ridge();
}

void FinGe::show_orientation()
{
	imshow("Orientation", orientation_display);
}

int val_to_index(double val, double min, double max, int n) {
	double gap = (max-min)/n;
	return floor((val-min)/gap);
}

double index_to_val(int index, double min, double max, int n) {
	double gap = (max-min)/n;
	return gap*(double(index)+.5)+min;
}

void FinGe::generate_ridge()
{
	Mat gb_cache[FG_CACHE_DEG*FG_CACHE_FREQ];
	for (int i=0; i<FG_CACHE_DEG; i++) {
		for (int j=0; j<FG_CACHE_FREQ; j++) {
			double theta = index_to_val(i,0,CV_PI*2, FG_CACHE_DEG)+CV_PI/2.0;
			double F = index_to_val(j,minF, maxF, FG_CACHE_FREQ);
			double sigma = sqrt(-9.0/(8.0*F*F*log(0.001)));
			gb_cache[FG_CACHE_INDEX(i,j)] = getGaborKernel(Size(2*FG_GABOR_FILTER_SIZE,2*FG_GABOR_FILTER_SIZE), sigma, theta, 1.0/F, 1, 0);
		}
	}

	Mat finger = Mat::zeros(size, CV_64FC1);
	randu(finger, 0, 1);
	Mat finger2 = finger < 0.001;
	finger2.convertTo(finger, CV_64FC1);
	if (mode==FG_MODE_DEBUG) {
		imshow("Master Fingerprint", finger);
		waitKey(0);
	}
	int b = FG_GABOR_FILTER_SIZE;

	while (true) {
		Mat layer = Mat::zeros(finger.size(), CV_64FC1);
		for (int i=0; i<size.width; i++) {
			for (int j=0; j<size.height; j++) {
				double theta = orientation.at<double>(j,i);
				theta = (theta<0)?theta+CV_PI*2:theta;
				double F = density.at<double>(j,i);
				//double sigma = sqrt(-9.0/(8.0*F*F*log(0.001)));
				//Mat filter = getGaborKernel(Size(2*b,2*b), sigma, theta, 1.0/F, 1, 0);
				int index = FG_CACHE_INDEX(val_to_index(theta,0,CV_PI*2,FG_CACHE_DEG),val_to_index(F, minF, maxF, FG_CACHE_FREQ));
				Rect fil_rec = Rect(max(b-i, 0), max(b-j,0), min(min(2*b, finger.size().width+b-i), b+i), min(min(2*b, finger.size().height+b-j), b+j));
				Rect fng_rec = Rect(max(i-b, 0), max(j-b,0), fil_rec.size().width, fil_rec.size().height);
				double t = sum(gb_cache[index](fil_rec).mul(finger(fng_rec)))[0];
				if (t<0) t=0;
				if (t>0) t=1;
				layer.at<double>(j,i) = t;
			}
		}
		if (double(abs(countNonZero(finger)-countNonZero(layer)))/size.area()>0.001) {
			finger = layer;
			if (mode==FG_MODE_DEBUG) {
				imshow("Master Fingerprint", finger);
				waitKey(0);
			}
		}
		else break;
	}
	master_fng = finger.mul(shape);
}

void FinGe::show_master_fingerprint()
{
	imshow("Master Fingerprint", master_fng);
	waitKey(1000);
}
