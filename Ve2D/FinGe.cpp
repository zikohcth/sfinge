#include "StdAfx.h"
#include "FinGe.h"
#include "misc.h"

FinGe::FinGe(void)
{
	shape_map = dir_map = dens_map = master_fin_img = 0;
	s_left = s_right = s_bottom = s_top = s_middle = 0;
	width = height = 0;

	dens_zoom=1;
	dens_amplify=0.5;
}

FinGe::~FinGe() {
	if (shape_map) delete[] shape_map;
	if (dens_map) delete[] dens_map;
	if (dir_map) delete[] dir_map;
	if (master_fin_img) delete[] master_fin_img;
}

void FinGe::set_shape(int left, int right, int top, int bottom, int middle) {
	s_left = left;
	s_right = right;
	s_top = top;
	s_bottom = bottom;
	s_middle = middle;
	width = s_left + s_right;
	height = s_top + s_middle + s_bottom;

	if (shape_map) delete[] shape_map;
	shape_map = new float[width*height];

	generate_shape();

	/*if (dir_map) delete[] dir_map;
	dir_map = new float[width*height];

	if (dens_map) delete[] dens_map;
	dens_map = new float[width*height];

	if (master_fin_img) delete[] master_fin_img;
	master_fin_img = new float[width*height];*/
}

void FinGe::generate_shape() {
	int i,j;

	//left bottom corner, center(left, bottom) 
	for (i=0; i<s_left; i++)
		for (j=0; j<s_bottom; j++)
			shape_map[j*width+i] = inside_elip(s_left-1, s_bottom-1, s_left, s_bottom, i, j);

	//right bottom corner, center(left, bottom) 
	for (i=s_left; i<width; i++)
		for (j=0; j<s_bottom; j++)
			shape_map[j*width+i] = inside_elip(s_left, s_bottom-1, s_right, s_bottom, i, j);

	//left top corner, center(left, bottom+mid) 
	for (i=0; i<s_left; i++)
		for (j=s_bottom+s_middle; j<height; j++)
			shape_map[j*width+i] = inside_elip(s_left-1, s_bottom+s_middle, s_left, s_top, i, j);

	//right top corner, center(left, bottom+mid) 
	for (i=s_left; i<width; i++)
		for (j=s_bottom+s_middle; j<height; j++)
			shape_map[j*width+i] = inside_elip(s_left, s_bottom+s_middle, s_right, s_top, i, j);

	for (i=0;i<width;i++)
		for (j=s_bottom;j<s_bottom+s_middle;j++)
			shape_map[j*width+i]=1;
}

void FinGe::debug_shape() {
	//PRINT DEBUG
	std::cout<<"SHAPE\n";
	for (int j=height-1;j>=0;j--) {
		for (int i=0;i<width;i++) {
			std::cout<<shape_map[j*width+i];
		}
		std::cout<<std::endl;
	}
}

void FinGe::set_density_map_args(float zoom, float amplify) {
	dens_zoom = zoom;
	dens_amplify = amplify;
	
	if (dens_map) delete[] dens_map;
	dens_map = new float[width*height];
	generate_density_map();
}


void FinGe::generate_density_map() {
	float* noise = render_clouds(width, height, dens_zoom, dens_amplify);
	memcpy(dens_map, noise, sizeof(float)*width*height);
	delete[] noise;
	for (int j=0;j<height;j++)
		for (int i=0;i<width;i++)
			dens_map[j*width+i] = dens_map[j*width+i]*shape_map[j*width+i];
	return;
}

void FinGe::debug_density_map() {
	//PRINT DEBUG
	printf("DENSITY MAP\n");
	for (int j=height-1;j>=0;j--) {
		for (int i=0;i<width;i++) printf("%1.0f",dens_map[j*width+i]*9);
		printf("\n");
	}
}

void FinGe::draw_shape( Bitmap^ bitmap )
{
	for (int j=0;j<height;j++)
		for (int i=0;i<width;i++) 
			if (shape_map[(height-j-1)*width+i])
				bitmap->SetPixel(i,j,Color::Black);
}

void FinGe::draw_density_map( Bitmap^ bitmap )
{
	System::Drawing::Color c;
	for (int j=0;j<height;j++)
		for (int i=0;i<width;i++) {
			int gray=(int)255*(1-dens_map[(height-j-1)*width+i]);
			bitmap->SetPixel(i,j,System::Drawing::Color::FromArgb(255, gray, gray, gray));
		}
}

int FinGe::get_width()
{
	return width;
}

int FinGe::get_height()
{
	return height;
}
