#include "pch.h"
#include "line.h"
_declspec(dllexport) line::line()
{

}

_declspec(dllexport) line::line(node m, node n)
{
	double y1, y2, x1, x2;
	this->node1 = m;
	this->node2 = n;
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

node _declspec(dllexport) line::getNode1()
{
	return this->node1;
}

node _declspec(dllexport) line::getNode2()
{
	return this->node2;
}

double _declspec(dllexport) line::getA()
{
	return this->a;
}

double _declspec(dllexport) line::getB()
{
	return this->b;
}

double _declspec(dllexport) line::getC()
{
	return this->c;
}

double _declspec(dllexport) line::getK()
{
	return this->k;
}

bool _declspec(dllexport) line::getExitK()
{
	return this->exitK;
}
bool _declspec(dllexport) line::judge(node n)
{
	return true;
}
bool _declspec(dllexport) line::operator ==(const line& other)
{
	if (a == other.a && b == other.b && c == other.c) return true;
	else return false;
}