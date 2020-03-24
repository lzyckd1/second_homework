#include "pch.h"
#include "Cycle.h"

_declspec(dllexport) Cycle::Cycle()
{

}
_declspec(dllexport) Cycle::Cycle(node n, double r)
{
	this->c = n;
	this->r = r;
}

node _declspec(dllexport) Cycle::getC()
{
	return this->c;
}

double _declspec(dllexport) Cycle::getR()
{
	return this->r;
}

bool _declspec(dllexport) Cycle::operator ==(const Cycle& other)
{
	if (c == other.c && r == other.r) return true;
	else return false;
}