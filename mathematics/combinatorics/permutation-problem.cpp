//permutation-problem.cpp
//Permutation Problem
//Ad Infinitum - Math Programming Contest June'14
//Author: derekhh

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

int f[1001][1001][11], g[1001][1001], c[1001][1001];

void init()
{
	for (int i = 1; i <= 1000; i++)
		c[i][0] = 1, c[i][1] = i, c[i][i] = 1;

	for (int i = 2; i <= 1000; i++)
		for (int j = 2; j <= 1000; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
}

int foo(int i,int j,int k)
{
	if (f[i][j][k] != -1) return f[i][j][k];
	if (i == 0) return f[i][j][k] = 1;

	int val1 = (k * (long long)foo(i - 1, min(i - 1, j), k)) % MOD;
	int val2 = (k * (long long)c[i - 1][j]) % MOD;
	int val3 = ((long long)val2 * foo(i - j - 1, min(i - j - 1, j), k-1)) % MOD;
	
	return f[i][j][k] = (val1 + MOD - val3) % MOD;
	
	/*
	int ret = 0;
	for (int l = 1; l <= min(i, j); l++)
		ret = (ret + (long long)c[i][l] * foo(i - l, min(i - l, j), k - 1)) % MOD;
	return f[i][j][k] = ret;
	*/
}

int main()
{
	memset(f, -1, sizeof(f));
	init();

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= 10; k++)
			{
				f[i][j][k] = foo(i, j, k);
			}
		}
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int val1 = (9 * (long long)foo(i - 1, min(i - 1, j), 10)) % MOD;
			int val2 = (9 * (long long)c[i - 1][j]) % MOD;
			int val3 = ((long long)val2 * foo(i - j - 1, min(i - j - 1, j), 9)) % MOD;
			g[i][j] = (val1 + MOD - val3) % MOD;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << g[n][min(n, k)] << endl;
	}
	return 0;
}