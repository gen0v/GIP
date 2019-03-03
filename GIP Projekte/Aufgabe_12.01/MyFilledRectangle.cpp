#include "MyFilledRectangle.h"


void MyFilledRectangle::draw()
{
	MyRectangle::draw();

	//lauter roter linien
	if ((this->x2 - this->x1 > 4 && (this->y2 - this->y1 > 4))) {
		for (int i = this->y1 + 2; i < this->y2-2; i++)
		{
			gip_draw_line(this->x1+2, i, this->x2-2, i, red);
		}
	}
}
