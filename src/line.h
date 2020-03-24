#pragma once
#ifdef CREATEDELL_API_DU
#else                                                                            
#define CREATEDELL_API_DU _declspec(dllimport)
#endif 
#include "node.h"
class CREATEDELL_API_DU line
{
private:
	node node1, node2;
	double a, b, c, k;
	bool exitK;
public:
	line();
	line(node m, node n);
	node getNode1();
	node getNode2();
	double getA();
	double getB();
	double getC();
	double getK();
	bool getExitK();
	bool judge(node n);
	bool operator ==(const line& other);
};
