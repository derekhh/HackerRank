//plus-minus.cpp
//Plus Minus
//Author: derekhh
//Jun 12, 2015

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n, pos = 0, neg = 0, zero = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		if (val > 0)
			pos++;
		else if (val < 0)
			neg++;
		else
			zero++;
	}
	cout << fixed;
	cout << setprecision(3) << 1.0 * pos / n << endl;
	cout << setprecision(3) << 1.0 * neg / n << endl;
	cout << setprecision(3) << 1.0 * zero / n << endl;
	return 0;
}