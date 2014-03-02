#pragma once

#include <time.h>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma comment(lib, "opencv_core248d.lib")
#pragma comment(lib, "opencv_imgproc248d.lib")
#pragma comment(lib, "opencv_highgui248d.lib")
#pragma comment(lib, "opencv_core248.lib")
#pragma comment(lib, "opencv_imgproc248.lib")
#pragma comment(lib, "opencv_highgui248.lib")

#define FG_SHAPE_NONE			0
#define FG_SHAPE_THUMB			1
#define FG_SHAPE_INDEX			2
#define FG_SHAPE_MIDDLE			3
#define FG_SHAPE_RING			4
#define FG_SHAPE_LITTLE			5

#define FG_CLASS_NONE			0
#define FG_CLASS_ARCH			1
#define FG_CLASS_TENTED_ARCH	2
#define FG_CLASS_LEFT_LOOP		3
#define FG_CLASS_RIGHT_LOOP		4
#define FG_CLASS_WHORL			5
#define FG_CLASS_TWIN_LOOP		6


#define FG_MODE_RUN				0
#define FG_MODE_DEBUG			1

#define FG_CACHE_DEG			36
#define FG_CACHE_FREQ			20
#define FG_CACHE_INDEX(deg,f)	(deg*FG_CACHE_FREQ+f)
#define FG_GABOR_FILTER_SIZE	10

using namespace cv;  // The new C++ interface API is inside this namespace. Import it.

class FinGe
{
public:
	FinGe(void);
	~FinGe(void);

	void random_shape(int shape=FG_SHAPE_NONE);
	void set_shape(int left, int right, int top, int bottom, int middle);
	void random_points(int fng_class=FG_CLASS_NONE);
	void set_points(int nCore, Point2d* cores, int nDelta, Point2d* deltas);
	void show_shape();
	void show_density();
	void show_orientation();
	void show_master_fingerprint();
	void set_ridge_width(int min_width, int max_width); //in pixel
	Size size;
	void set_mode(int mode=FG_MODE_DEBUG);

private:
	int sL, sR, sT, sB, sM; //left right top bottom middle of the shape
	Point2d* cores;
	Point2d* deltas;
	int nCore;
	int nDelta;

	void generate_shape();
	void generate_density();
	void generate_orientation();
	void generate_ridge();
	Mat shape;
	Mat density;
	Mat density_steps;
	Mat orientation;
	Mat orientation_display;
	Mat master_fng;
	int mode;

	double minF;//min frequency
	double maxF;//max frequency
};

