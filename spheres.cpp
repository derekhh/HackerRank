//spheres.cpp
//Spheres
//Ad Infinitum - Math Programming Contest June'14
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r1, r2;
		cin >> r1 >> r2;
		int x1, y1, z1, x2, y2, z2;
		int a1x, a1y, a1z, a2x, a2y, a2z;
		cin >> x1 >> y1 >> z1 >> a1x >> a1y >> a1z;
		cin >> x2 >> y2 >> z2 >> a2x >> a2y >> a2z; 
		double a = ((a1x - a2x) * (a1x - a2x) + (a1y - a2y) * (a1y - a2y) + (a1z - a2z)*(a1z - a2z)) * 0.25;
		double b = (x1 - x2) * (a1x - a2x) + (y1 - y2) * (a1y - a2y) + (z1 - z2) * (a1z - a2z);
		double c = (x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) - (r1 + r2) * (r1 + r2);
		//cout << a << " " << b << " " << c << endl;
		string res;
		if (a == 0) 
		{
			if (b == 0)
			{
				res = (c >= 0)? "NO" : "YES";
			}
			else
			{
				res = (b > 0 && c >= 0) ? "NO" : "YES";
			}
		}
		else
		{
			if (a < 0) res = "YES";
			else
			{
				if (b <= 0)
				{
					if (((4 * a * c - b * b) / (4 * a)) >= 0)
						res = "NO";
					else
						res = "YES";
				}
				else
				{
					if (c >= 0)
						res = "NO";
					else
						res = "YES";
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}