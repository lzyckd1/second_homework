#include "pch.h"
#include "lise.h"
_declspec(dllexport) lise::lise()
{

}

_declspec(dllexport) lise::lise(node m, node n)
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

node _declspec(dllexport) lise::getNode1()
{
	return this->node1;
}

node _declspec(dllexport) lise::getNode2()
{
	return this->node2;
}

double _declspec(dllexport) lise::getA()
{
	return this->a;
}

double _declspec(dllexport) lise::getB()
{
	return this->b;
}

double _declspec(dllexport) lise::getC()
{
	return this->c;
}

double _declspec(dllexport) lise::getK()
{
	return this->k;
}

bool _declspec(dllexport) lise::getExitK()
{
	return this->exitK;
}
bool _declspec(dllexport) lise::judge(node n)
{
	node n1 = this->getNode1(), n2 = this->getNode2();
	double x1 = n1.getX(), x2 = n2.getX(), y1 = n1.getY(), y2 = n2.getY(), tmp;
	double x = n.getX(), y = n.getX();
	if (x1 > x2) {
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	if (y1 > y2) {
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	if (x <= x2 && x >= x1 && y <= y2 && y >= y1)
	{
		return true;
	}
	return false;
}

bool _declspec(dllexport) lise::operator ==(const lise& other)
{
	if (node1 == other.node1 && node2 == other.node2) return true;
	else if (node1 == other.node2 && node2 == other.node1)return true;
	else if (a == other.a && b == other.b && c == other.c) {
		if ((node1.x - other.node1.x) * (node2.x - other.node1.x) < 0)return true;
		if ((node1.x - other.node2.x) * (node2.x - other.node2.x) < 0)return true;
		if ((node1.y - other.node1.y) * (node2.y - other.node1.y) < 0)return true;
		if ((node1.y - other.node2.y) * (node2.y - other.node2.y) < 0)return true;
		return false;
	}
	else return false;
}