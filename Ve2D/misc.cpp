#include "stdafx.h"
#include "misc.h"

int inside_elip(int cx, int cy, int a, int b, int x, int y) {
	int t = (x-cx)*(x-cx)*b*b + (y-cy)*(y-cy)*a*a-a*a*b*b;
	if (t<0)
		return 1;
	return 0;
}

double findnoise2(double x,double y) {
	int n=(int)x+(int)y*57;
	n=(n<<13)^n;
	int nn=(n*(n*n*60493+19990303)+1376312589)&0x7fffffff;
	return 1.0-((double)nn/1073741824.0);
}

double interpolate(double a,double b,double x) {
	double ft=x * 3.1415927;
	double f=(1.0-cos(ft))* 0.5;
	return a*(1.0-f)+b*f;
}

double noise(double x,double y) {
	double floorx=(double)((int)x);//This is kinda a cheap way to floor a double integer.
	double floory=(double)((int)y);
	double s,t,u,v;//Integer declaration
	s=findnoise2(floorx,floory); 
	t=findnoise2(floorx+1,floory);
	u=findnoise2(floorx,floory+1);//Get the surrounding pixels to calculate the transition.
	v=findnoise2(floorx+1,floory+1);
	double int1=interpolate(s,t,x-floorx);//Interpolate between the values.
	double int2=interpolate(u,v,x-floorx);//Here we use x-floorx, to get 1st dimension. Don't mind the x-floorx thingie, it's part of the cosine formula.
	return interpolate(int1,int2,y-floory);//Here we use y-floory, to get the 2nd dimension.
}

float *render_clouds(int w,int h,double zoom,double p) {
	int octaves=2;
	float* cloud = new float[w*h];
	for(int y=0;y<h;y++)
	{
		for(int x=0;x<w;x++)
		{
			double getnoise =0;
			for(int a=0;a<octaves-1;a++)//This loops trough the octaves.
			{
				double frequency = pow(2.0,a);//This increases the frequency with every loop of the octave.
				double amplitude = pow(p,a);//This decreases the amplitude with every loop of the octave.
				getnoise += noise(((double)x)*frequency/zoom,((double)y)/zoom*frequency)*amplitude;//This uses our perlin noise functions. It calculates all our zoom and frequency and amplitude
			}
			getnoise = (getnoise+1)/2.0;
			if (getnoise>1) getnoise=1.0;
			if (getnoise<0) getnoise=0.0;
			cloud[y*w+x] = getnoise;
		}
	}
	return cloud;
}