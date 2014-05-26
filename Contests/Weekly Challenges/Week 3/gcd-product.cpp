//gcd-product.cpp
//GCD Product
//Weekly Challenges - Week 3
//Author: derekhh

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

bool isprime[15000001];
int factor[15000000];

long long ModExp(long long a, long long b, long long n)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % n;
		d = (d*d) % n;
		b >>= 1;
	}
	return c;
}

int main()
{
	int n, m;
	cin >> n >> m;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	int nf = 0;
	for (int i = 2; i <= min(n, m); i++)
	{
		if (isprime[i])
		{
			for (int j = i + i; j <= min(n, m); j += i)
				isprime[j] = false;
			factor[nf++] = i;
		}
	}

	long long ans = 1;

	for (int i = 0; i < nf; i++)
	{
		long long tmp = 0, now = factor[i];
		while (n / now && m / now)
		{
			tmp += (n / now) * (m / now);
			now *= factor[i];
		}
		ans = (ans * ModExp(factor[i], tmp, MOD)) % MOD;
	}
	cout << ans << endl;
	return 0;
}