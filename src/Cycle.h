#pragma once
#ifdef CREATEDELL_API_DU
#else                                                                            
#define CREATEDELL_API_DU _declspec(dllimport)
#endif 
#include "node.h"
class CREATEDELL_API_DU Cycle {
private:
	node c;
	double r;
public:
	Cycle();
	Cycle(node n, double r);
	node getC();
	double getR();
	bool operator ==(const Cycle& other);
};