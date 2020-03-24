#pragma once

#ifdef CREATEDELL_API_DU
#else                                                                            
#define CREATEDELL_API_DU _declspec(dllimport)
#endif 
#include "node.h"
class CREATEDELL_API_DU rays
{
private:
	node start, n;
	double a, b, c, k;
	bool exitK;
public:
	rays();
	rays(node m, node n);
	node getStart();
	node getN();
	double getA();
	double getB();
	double getC();
	double getK();
	bool getExitK();
	bool judge(node n);
	bool operator ==(const rays& other);
};
