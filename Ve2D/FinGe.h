#pragma once

using namespace System::Drawing;

ref class FinGe
{
public:
	FinGe(void);
	~FinGe(void);

	void set_shape(int left, int right, int top, int bottom, int middle);
	/*void set_directional_map_args(int classify, int* parameters);*/
	void set_density_map_args(float zoom, float amplify);
	/*void set_ridge_args(int seeds, int* parameters);*/

	void debug_shape();
	void debug_density_map();
	void draw_shape(Bitmap^ bitmap);
	void draw_density_map(Bitmap^ bitmap);
	int get_width();
	int get_height();
private:
	void generate_shape();
	/*void generate_directional_map();*/
	void generate_density_map();
	/*void generate_ridge();*/

	int s_left, s_right, s_top, s_bottom, s_middle;
	int width, height;
	float* shape_map;
	
	float* dir_map;

	float dens_zoom;
	float dens_amplify;
	float* dens_map;

	float* master_fin_img;
};

