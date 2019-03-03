#include "MyRectangle.h"



void MyRectangle::set(int varx, int varxx, int vary, int varyy)
{
	x1 = varx;
	x2 = varxx;
	y1 = vary;
	y2 = varyy;
}

void MyRectangle::draw() {
	gip_draw_rectangle(x1, y1, x2, y2, blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) {
	if (this->x1 < this->x2 && this->x2 < other.x1 && other.x1 < other.x2) {
		//|1| |2|
		return true;
	}
	else if (other.x1 < other.x2 && other.x2 < this->x1 && this->x1 < this->x2) {
		//|2| |1|
		return true;
	}
	else if (this->y1 < this->y2 && this->y2 < other.y1 && other.y1 < other.y2) {
		//|1|
		//|2|
		return true;
	}
	else if (other.y1 < other.y2 && other.y2 < this->y1 && this->y1 < this->y2) {
		//|2|
		//|1|
		return true;
	}


	return false;
}