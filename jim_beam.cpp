//jim_beam.cpp
//Jim Beam
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

#define EPS 1e-8
#define geq(x,y) ((x)+EPS>=(y))

struct Point
{
	double x, y;
	Point(double x0 = 0, double y0 = 0) :x(x0), y(y0){}
};

struct Line
{
	Point p1, p2;
};

double times(Point p0, Point p1, Point p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}

bool LineSegIntersect(Line L1, Line L2)
{
	return(geq(max(L1.p1.x, L1.p2.x), min(L2.p1.x, L2.p2.x))
		&& geq(max(L2.p1.x, L2.p2.x), min(L1.p1.x, L1.p2.x))
		&& geq(max(L1.p1.y, L1.p2.y), min(L2.p1.y, L2.p2.y))
		&& geq(max(L2.p1.y, L2.p2.y), min(L1.p1.y, L1.p2.y))
		&& times(L1.p1, L2.p1, L1.p2)*times(L1.p1, L2.p2, L1.p2) <= EPS
		&&times(L2.p1, L1.p1, L2.p2)*times(L2.p1, L1.p2, L2.p2) <= EPS);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Line L1, L2;
		L1.p1 = Point(0, 0);
		cin >> L2.p1.x >> L2.p1.y >> L2.p2.x >> L2.p2.y >> L1.p2.x >> L1.p2.y;
		if (LineSegIntersect(L1, L2))
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}