//swappermutation.cpp
//Swap Permutation
//Weekly Challenges - Week 5
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;
long long f[2501][2501], fs[2501][2501];
long long g[2501][2501];

int main()
{
	int n, k;
	cin >> n >> k;
	f[1][0] = fs[1][0] = 1;
	for (int i = 1; i <= k; i++)
		fs[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j != min(i - 1, j))
				f[i][j] = (fs[i - 1][j] + MOD - fs[i - 1][j - min(i - 1, j) - 1]) % MOD;
			else
				f[i][j] = fs[i - 1][j];

			//printf("f[%d][%d] = %d\n", i, j, f[i][j]);

			if (j == 0)
				fs[i][j] = f[i][j] % MOD;
			else
				fs[i][j] = (fs[i][j - 1] + f[i][j]) % MOD;
		}
	}
	
	g[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (i == j)
				g[i][j] = 1;
			else
				g[i][j] = (g[i - 1][j - 1] + (i - 1) * g[i - 1][j]) % MOD;

	int ret1 = 0, ret2 = 0;
	for (int i = 0; i <= k; i++)
		if (i % 2 == k % 2)
			ret1 = (ret1 + f[n][i]) % MOD;

	for (int i = 0; i <= n; i++)
		if (n - i <= k)
			ret2 = (ret2 + g[n][i]) % MOD;

	cout << ret1 << " " << ret2 << endl;
	return 0;
}