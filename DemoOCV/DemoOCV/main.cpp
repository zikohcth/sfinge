#include <stdio.h>
#include <iostream>
#include <time.h>

#include "FinGe.h"

using namespace cv;  // The new C++ interface API is inside this namespace. Import it.

void generate_ridge() {
	double wavelength = 50;
	double frequency = 1.0/wavelength;
	double sigma = sqrt(-9.0/(8.0*frequency*frequency*log(0.001)));
	printf("%f",sigma);
	Mat gb = getGaborKernel(Size(200,200),sigma, 0, wavelength, 1, 0);
	imshow("GB kernel", gb);
}

/*int val_to_index2(double val, double min, double max, int n) {
	double gap = (max-min)/n;
	return floor(val/gap);
}*/

void main() {
	//generate_density_img(400,200);
	//namedWindow("Finger shape", WINDOW_AUTOSIZE);
	//namedWindow("Density", WINDOW_AUTOSIZE);
	waitKey(1000);
	FinGe finge;
	finge.set_mode(FG_MODE_DEBUG);
	finge.set_shape(100,110,150,90,50);
	Point2d cores[] = {Point2d(75.5,100.5)};
	Point2d deltas[] = {Point2d(130.5,187.5)};
	finge.set_points(1,cores, 1, deltas);
	finge.show_shape();
	finge.show_density();
	finge.show_orientation();
	finge.show_master_fingerprint();
	waitKey(0);

	/*std::cout<<val_to_index2(0.13, 0.066666666, 0.2, 5);
	std::cin.get();*/
	return;
}