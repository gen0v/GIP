#pragma once
class MyRectangle
{
public:
	MyRectangle()
		:x1(0), y1(0), x2(20), y2(20) {}

	MyRectangle(int xa, int ya, int xx, int yy)
		:x1(xa), y1(ya), x2(xx), y2(yy) {}

	int get_x1() { return x1; }
	int get_x2() { return x2; }
	int get_y1() { return y1; }
	int get_y2() { return y2; }

	int set_x1(int var) { x1 = var; }
	int set_x2(int var) { x2 = var; }
	int set_y1(int var) { y1 = var; }
	int set_y2(int var) { y2 = var; }

	void draw();
	void set(int varx, int varxx, int vary, int varyy);
	bool does_not_collide_with(const MyRectangle& other);


private:
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
};




