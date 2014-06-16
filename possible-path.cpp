//possible-path.cpp
//Possible Path
//Ad Infinitum - Math Programming Contest June'14
//Author: derekhh

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		if (gcd(abs(a), abs(b)) == gcd(abs(x), abs(y)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}