//lucy-and-flowers.cpp
//Lucy and Flowers
//Weekly Challenges - Week 4
//Author: derekhh

#include<cstdio>
#include<cstring>
using namespace std;

const int MOD = 1000000009;

long long f[5001];
long long c[5001][5001];
long long memo[5001];

void init()
{
	f[0] = f[1] = 1;
	for (int i = 2; i <= 5000; i++)
	{
		for (int j = 1; j <= i; j++)
			f[i] = (f[i] + (f[j - 1] * f[i - j]) % MOD) % MOD;
	}
}

void initc()
{
	for (int i = 1; i <= 5000; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 2; i <= 5000; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

int main()
{
	init();
	initc();
	memset(memo, -1, sizeof(memo));
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (memo[n] != -1)
			printf("%lld\n", memo[n]);
		else
		{
			long long ret = 0;
			for (int i = 1; i <= n; i++)
				ret = (ret + c[n][i] * f[i]) % MOD;
			printf("%lld\n", ret);
			memo[n] = ret;
		}
	}
	return 0;
}