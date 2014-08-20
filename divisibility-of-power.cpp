//divisibility-of-power.cpp
//Divisibility of Power
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<cstdio>
#include<algorithm>
using namespace std;

long long mulmod(long long a, long long b, long long m) 
{
	long long res = 0;
	while (a != 0) 
	{
		if (a & 1) res = (res + b) % m;
		a >>= 1;
		b = (b << 1) % m;
	}
	return res;
}

long long ModExp(long long a, long long b, long long n)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = mulmod(c, d, n);
		d = mulmod(d, d, n);
		b >>= 1;
	}
	return c % n;
}

long long a[300001];

int foo(long long a, long long b)
{
	if (a < 2) return (int)a;
	if (b == 0) return 1;
	if (b == 1) 
	{
		if (a > 64) return 64;
		return (int) a;
	}
	if (a > 8 || b > 6) return 64;
	int ret = (int)pow(a, b);
	return ret > 64 ? 64 : ret;
}

int main()
{
	long long n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	long long q;
	scanf("%lld", &q);
	while (q--)
	{
		long long i, j, x;
		scanf("%lld%lld%lld", &i, &j, &x);
		int res = 1;
		int k = min(j, i + 6);
		if (i + 7 <= j && a[i + 7] == 0) k--;
		for (; k > i; k--)
			res = foo(a[k], res);
		long long ans = ModExp(a[i], res, x);
		if (ans == 0) printf("Yes\n", i, j, x);
		else printf("No\n", i, j, x);
	}
	return 0;
}