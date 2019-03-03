#pragma once
#include "MyRectangle.h"
#include "CImgGIP05.h"

class MyFilledRectangle : public MyRectangle
{

	public:
		MyFilledRectangle(int xa, int ya, int xx, int yy): MyRectangle(xa, ya, xx, yy) {}
		void draw();
};