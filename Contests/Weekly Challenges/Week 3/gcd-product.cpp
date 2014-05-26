//gcd-product.cpp
//GCD Product
//Weekly Challenges - Week 3
//Author: derekhh

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 100000007;

bool isprime[15000001];
int factor[1000000];

int ModExp(int a, int b, int n)
{
	int c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % n;
		d = (1LL * d*d) % n;
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
		int tmp = 0;
		long long now = factor[i];
		while (true)
		{
			if (n / now == 0 || m / now == 0) break;
			tmp += 1LL * (n / now) * (m / now);
			now *= factor[i];
		}
		ans = (ans * ModExp(factor[i], tmp, MOD)) % MOD;
	}
	cout << ans << endl;
	return 0;
}