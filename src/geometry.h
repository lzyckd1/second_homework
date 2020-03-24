#ifndef GEOMETRY_H
#define GEOMETRY_H

#include<math.h>
class node
{
private:
    
public:
	double x, y;
    node();
    node(double x, double y);
    double getX();
    double getY();
    bool operator <(const node& other) const
    {
        if (x < other.x) return true;
        else if (x == other.x  && y < other.y) return true;
        else return false;
    }
	bool operator ==(const node& other) const
	{
		if (x == other.x && y == other.y ) return true;
		else return false;
	}
};

class line
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
	bool operator ==(const line& other) const
	{
		if (node1 == other.node1 && node2 == other.node2) return true;
		else if (node1 == other.node2 && node2 == other.node1)return true;
		else return false;
	}

};



class rays
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
	bool operator ==(const rays& other) const
	{
		if (start == other.start) {
			if (a == other.a && b == other.b && c == other.c)
			{
				double x0 = start.x, y0 = start.y;
				double x1 = other.n.x, y1 = other.n.y;
				double x2 = n.x, y2 = n.y;
				if ((x1 > x0 && x2 > x0) || (x1 < x0 && x2 < x0) || (x1 == x0 && x2 == x0)) {
					if ((y1 > y0 && y2 > y0) || (y1 < y0 && y2 < y0) || (y1 == y0 && y2 == y0)) {
						return true;
					}
				}
			}
		}
		return false;
	}
};


class lise
{
private:
    node node1, node2;
    double a, b, c, k;
    bool exitK;
public:
    lise();
    lise(node m, node n);
    node getNode1();
    node getNode2();
    double getA();
    double getB();
    double getC();
    double getK();
    bool getExitK();
    bool judge(node n);
	bool operator ==(const lise& other) const
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
};

class Cycle {
private:
    node c;
    double r;
public:
    Cycle();
    Cycle(node n, double r);
    node getC();
    double getR();
	bool operator ==(const Cycle& other) const
	{
		if (c == other.c && r == other.r) return true;
		else return false;
	}
};



#endif // GEOMETRY_H
