//roy-and-alpha-beta-trees.cpp
//Roy and alpha-beta trees
//Weekly Challenges - Week 4
//Author: derekhh

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long c[151], a[151];
int alpha, beta;
const int MOD = 1000000009;

void init()
{
	c[0] = c[1] = 1;
	for (int i = 2; i <= 150; i++)
		for (int j = 0; j < i; j++)
			c[i] = ((c[j] * c[i - j - 1] % MOD) + c[i]) % MOD;
}

long long f[151][151][2];

long long dp(int i, int j, int flag)
{
	if (f[i][j][flag] != -1)
		return f[i][j][flag];

	if (i == j)
	{
		if (flag == 0) return f[i][j][flag] = a[i] * alpha % MOD;
		else return f[i][j][flag] = (MOD - (a[i] * beta % MOD) % MOD);
	}
	else
	{
		long long sum = 0;
		for (int idx = i; idx <= j; idx++)
		{
			if (idx > i) sum = (sum + c[j - idx] * dp(i, idx - 1, 1 - flag)) % MOD;
			if (idx < j) sum = (sum + c[idx - i] * dp(idx + 1, j, 1 - flag)) % MOD;

			long long val = c[idx - i];
			val = (val * c[j - idx]) % MOD;
			val = (val * a[idx]) % MOD;
			if (flag == 0)
				val = (val * alpha) % MOD;
			else
				val = (MOD - ((val * beta) % MOD)) % MOD;
			sum = (sum + val) % MOD;
		}
		return f[i][j][flag] = sum % MOD;
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		memset(f, -1, sizeof(f));
		int n;
		cin >> n >> alpha >> beta;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		cout << dp(0, n - 1, 0) << endl;
	}
	return 0;
}