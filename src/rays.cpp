#include "pch.h"
#include "rays.h"
_declspec(dllexport) rays::rays()
{

}
_declspec(dllexport) rays::rays(node m, node n)
{
	double y1, y2, x1, x2;
	this->start = m;
	this->n = n;
	x1 = m.getX();
	y1 = m.getY();
	x2 = n.getX();
	y2 = n.getY();
	this->a = y1 - y2;
	this->b = x2 - x1;
	this->c = x1 * y2 - x2 * y1;
	this->k = 0;
	if (x1 == x2) {
		this->exitK = false;
	}
	else {
		this->exitK = true;
		this->k = (y2 - y1) / (x2 - x1);
	}
}
node _declspec(dllexport) rays::getStart()
{
	return this->start;
}
node _declspec(dllexport) rays::getN()
{
	return this->n;
}
double _declspec(dllexport) rays::getA()
{
	return this->a;
}
double _declspec(dllexport) rays::getB()
{
	return this->b;
}
double _declspec(dllexport) rays::getC()
{
	return this->c;
}
double _declspec(dllexport) rays::getK()
{
	return this->k;
}
bool _declspec(dllexport) rays::getExitK()
{
	return this->exitK;
}
bool _declspec(dllexport) rays::judge(node t)
{
	node n1 = this->getStart(), n2 = this->getN();
	double x1 = n1.getX(), x2 = n2.getX(), y1 = n1.getY(), y2 = n2.getY(), tmp;
	double x = t.getX(), y = t.getX();
	if (x1 <= x2) {
		if (x < x1)return false;
	}
	else {
		if (x > x1)return false;
	}
	if (y1 <= y2) {
		if (y < y1)return false;
	}
	else {
		if (y > y1)return false;
	}
	return true;
}
bool _declspec(dllexport) rays::operator ==(const rays& other)
{
	if (start == other.start) {
		if (a == other.a && b == other.b && c == other.c)
		{
			double x0 = start.x, y0 = start.y;
			double x1 = other.n.x, y1 = other.n.y;
			double x2 = n.x, y2 = n.y;
			if ((x1 > x0&& x2 > x0) || (x1 < x0 && x2 < x0) || (x1 == x0 && x2 == x0)) {
				if ((y1 > y0&& y2 > y0) || (y1 < y0 && y2 < y0) || (y1 == y0 && y2 == y0)) {
					return true;
				}
			}
		}
	}
	return false;
}
