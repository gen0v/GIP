#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
using namespace cimg_library;

int main() {
	int counter = 0;
	gip_load_image("Campus_Eupener_Strasse.bmp");
	




	while (gip_window_not_closed())
	{
		gip_load_image("Campus_Eupener_Strasse.bmp");
		//gip_draw_rectangle(0, 0, gip_win_size_x, gip_win_size_y, black);

		gip_stop_updates();
		for (int y = 0; y <gip_win_size_y; y++)
		{
			for (int x = 0; x < gip_win_size_x; x++)
			{
				if (gip_distance(x, y, gip_mouse_x(), gip_mouse_y()) > 100) {
					gip_set_grey(x, y, 0);
				}
				else gip_set_grey(x, y, gip_get_grey(x,y));
			}

		}
		gip_start_updates();
		gip_sleep(2);
	}
	return 0;
}