#pragma once
#ifdef CREATEDELL_API_DU
#else                                                                            
#define CREATEDELL_API_DU _declspec(dllimport)
#endif 
class  node
{
public:
	double x, y;
	node();
	node(double x, double y);
	double getX();
	double getY();
	bool operator <(const node& other)const
	{
		if (x < other.x) return true;
		else if (x == other.x && y < other.y) return true;
		else return false;
	}

	bool operator ==(const node& other)const
	{
		if (x == other.x && y == other.y) return true;
		else return false;
	}
};
