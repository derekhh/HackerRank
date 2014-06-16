//ichigo-and-revenge.cpp
//Ichigo and Revenge
//Ad Infinitum - Math Programming Contest June'14
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

int inv(int num)
{
	return ModExp(num, MOD - 2, MOD);
}

int fact[100001];

void init()
{
	fact[0] = 1;
	for (int i = 1; i <= 100000; i++)
		fact[i] = (fact[i - 1] * (long long)i) % MOD;
}

int c(int n, int m)
{
	long long tmp = ((long long)fact[n] * inv(fact[m])) % MOD;
	return (tmp * inv(fact[n - m])) % MOD;
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		int u, v, k, p;
		cin >> u >> v >> k >> p;
		long long val1 = c(u*p, v*p);
		long long val2 = c(u, v);
		long long val3 = inv(p);
		long long val4 = (val1 + MOD - val2) % MOD;
		long long val = (val4 * val3) % MOD;
		if (k == 0) val = (val + c(u, v)) % MOD;
		cout << val << endl;
	}
	return 0;
}