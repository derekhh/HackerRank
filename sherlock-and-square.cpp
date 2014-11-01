//sherlock-and-square.cpp
//Sherlock and Square
//Weekly Challenges - Week 11
//Author: derekhh

#include<iostream>
using namespace std;

const int MOD = 1000000007;

int ModExp(int a, int b, int n)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % n;
		d = (d*d) % n;
		b >>= 1;
	}
	return (int)c;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (ModExp(2, n + 1, MOD) + 2) % MOD << endl;
	}
	return 0;
}