//die-hard-3.cpp
//Die Hard 3
//Weekly Challenges - Week 7
//Author: derekhh

#include<iostream>
#include<algorithm>
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
		int a, b, c;
		cin >> a >> b >> c;
		if (c % gcd(a, b) == 0 && c <= max(a, b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}