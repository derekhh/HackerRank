//euler001.cpp
//Project Euler #1: Multiples of 3 and 5
//ProjectEuler +
//Author: derekhh

#include<iostream>
using namespace std;

long long foo(long long n, int t)
{
	return (t + (n - 1) / t * t) *((n - 1) / t) / 2;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		cout << foo(n, 3) + foo(n, 5) - foo(n, 15) << endl;
	}
	return 0;
}