#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

int main() {

	int box_size = gip_win_size_x / 50;
	gip_color color;

	gip_load_image("Campus_Eupener_Strasse.bmp");

	//gip_draw_rectangle(0, 0, gip_win_size_x, gip_win_size_y, black);

	gip_stop_updates();
	while (gip_window_not_closed())
	{
		gip_load_image("Campus_Eupener_Strasse.bmp");
		//gip_draw_rectangle(0, 0, gip_win_size_x, gip_win_size_y, black);

		gip_stop_updates();
		/*
		for (int y = 0; y <gip_win_size_y; y+=10)
		{
			for (int x = 0; x < gip_win_size_x; x+=10)
			{
				gip_get_color(x+1, y+1, color);
				gip_draw_rectangle(x, y, x+10, y+10, color);
			}

		}
		*/
		for (int y = 0; y <gip_win_size_y; y += box_size)
		{
			for (int x = 0; x < gip_win_size_x; x += box_size)
			{
				gip_get_color(x, y, color);
				gip_draw_rectangle(x, y, x + box_size-1, y + box_size-1, color);
			}

		}
		gip_start_updates();
		gip_sleep(2);
	}

	return 0;

}