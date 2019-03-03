#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;
int main()
{
	// F�r das "blaue Spielfeld" ...
	const int left_border = 100;
	const int right_border = 500;
	// F�r Ausdehnung und Position des wei�en Quadrats ...
	int x = 200, y = 300;
	const int rectangle_size = 50;
	int delta = 10;
	bool left = true, right = false;
	gip_white_background();
	while (gip_window_not_closed())
	{
		// Blaues "Spielfeld" neu zeichnen
		// (�bermalt dann auch das letzte wei�e Quadrat) ...
		gip_draw_rectangle(left_border, 100, // linke obere Ecke
			right_border, 500, // rechte untere Ecke
			blue);
		// Wei�es Quadrat neu zeichnen an der Position x,y ...
		gip_draw_rectangle(x, y, // linke obere Ecke
			x + rectangle_size, // rechte untere Ecke
			y + rectangle_size,
			white);
		// N�chste Position des wei�en Quadrats berechnen.
		// Dabei ber�cksichtigen, dass das Quadrat von den R�ndern des
		// blauen "Spielfelds" abprallen muss ...
		/* Ihr Code zur Berechnung der neuen Werte von x und y hier */
		if (x + 50 < right_border && left == true)
		{
			x = x + delta;
			if (x + 50 == right_border) {
				right = true;
				left = false;
			}
		}
		else if (x > left_border && right == true) {
			x = x - delta;
			
			if (x == left_border) {
				left = true;
				right = false;
			}
		}
		gip_wait(100);
	}
	return 0;
}