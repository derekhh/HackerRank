//akhil-and-gf.cpp
//Akhil and GF
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<iostream>
using namespace std;

long long mod_mul(long long x, long long y, long long n)
{
	if (!x) return 0;
	return (((x & 1)*y) % n + (mod_mul(x >> 1, y, n) << 1) % n) % n;
}

long long ModExp(long long a, long long b, long long n)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = mod_mul(c, d, n);
		d = mod_mul(d, d, n);
		b >>= 1;
	}
	return c;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;
		long long tmp = ModExp(10, n, 9 * m);
		tmp--;
		if (tmp < 0) tmp += 9 * m;
		tmp /= 9;
		cout << tmp << endl;
	}
	return 0;
}