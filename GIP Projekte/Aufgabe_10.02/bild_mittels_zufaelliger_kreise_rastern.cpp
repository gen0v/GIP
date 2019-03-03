
#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

using namespace std;
using namespace cimg_library;

struct farb_speicherung
{
	int x;
	int y;
	int R;
	int G;
	int B;
};

int main() {
	gip_load_image("Campus_Eupener_Strasse.bmp");
	int r_x = 0, r_y = 0;
	//Array mit 50k Eintraegen definieren
	farb_speicherung my_array[50000];
	for (int i = 0; i < 50000; i++)
	{
		r_x = gip_random(0, gip_win_size_x - 1);
		r_y = gip_random(0, gip_win_size_y - 1);
		my_array[i] = { r_x,r_y,gip_get_red(r_x, r_y),gip_get_green(r_x, r_y),gip_get_blue(r_x, r_y) };

		/*
		my_array[i].x = gip_random(0, gip_win_size_x - 1);
		my_array[i].y = gip_random(0, gip_win_size_y - 1);
		my_array[i].R = gip_get_red(my_array[i].x, my_array[i].y);
		my_array[i].G = gip_get_green(my_array[i].x, my_array[i].y);
		my_array[i].B = gip_get_blue(my_array[i].x, my_array[i].y);
		*/
	}

	cout << gip_win_size_y;
	//int box_size = gip_win_size_x / 50;
	//gip_color color;

	
	gip_stop_updates();
	for (int i = 0; i < 50000; i++)
	{
		
		gip_color color = { my_array[i].R, my_array[i].G, my_array[i].B };
		gip_draw_circle(my_array[i].x, my_array[i].y, 5, color);
	}
	gip_start_updates();

	gip_sleep(10);
	return 0;

}