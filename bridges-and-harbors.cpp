//bridges-and-harbors.cpp
//Bridges and Harbors
//Ad Infinitum - Math Programming Contest June'14
//Author: derekhh

#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int p[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int cnt[101][25], sum[101][25];

void init()
{
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= 100; i++)
	{
		int num = i, cur = 0;
		while (num != 1)
		{
			while (num % p[cur] == 0) num /= p[cur], cnt[i][cur]++;
			cur++;
		}
	}

	for (int i = 0; i < 25; i++)
		sum[1][25] = cnt[1][25];

	for (int i = 2; i <= 100; i++)
		for (int j = 0; j < 25; j++)
			sum[i][j] = cnt[i][j] + sum[i - 1][j];
}

int n, m, k, mod;

int combval[11000][110];

int comb(int _n, int _m)
{
	int __n = n - _n;
	if (combval[__n][_m] != -1) return combval[__n][_m];

	if  (_m == 0) return 1;

	int v[100], nv = 0;
	int c[25];
	memcpy(c, sum[_m], sizeof(c));
	for (int i = _n - _m + 1; i <= _n; i++)
	{
		int num = i;
		for (int j = 0; j < 25; j++)
		{
			while (num % p[j] == 0 && c[j] > 0)
				num /= p[j], c[j]--;
		}
		v[nv++] = num;
	}
	int ret = 1;
	for (int i = 0; i < nv; i++)
		ret = ((long long)ret * v[i]) % mod;
	return combval[__n][_m] = ret;
}

int ModExp(int a, int b)
{
	long long c = 1, d = a;
	while (b)
	{
		if (b & 1) c = (c*d) % mod;
		d = (d*d) % mod;
		b >>= 1;
	}
	return (int)c;
}

int fooval[11000][110];

int foo(int i, int j)
{
	int _i = n - i;
	if (fooval[_i][j] != -1) return fooval[_i][j];
	
	if (i == 0) return 1;

	if (j == 0)
	{
		int ret = ModExp(n - m, i);
		fooval[_i][j] = ret;
		return ret;
	}

	if (n - m - i > k * (m - j)) return 0;

	int ret = 0;
	for (int l = 0; l <= min(i, k); l++)
		ret = (ret + (long long)comb(i, l) * foo(i - l, j - 1)) % mod;
	fooval[_i][j] = ret;
	return ret;
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		memset(combval, -1, sizeof(combval));
		memset(fooval, -1, sizeof(fooval));
		cin >> n >> m >> k >> mod;
		if (n == m) cout << 1 % mod << endl;
		else
		{
			int res = 0;
			for (int i = 1; i <= min(n - m, k); i++)
				res = (res + (long long)comb(n - m - 1, i - 1) * foo(n - m - i, m - 1)) % mod;
			res = ((long long)res * m) % mod;
			res = ((long long)res * comb(n, m)) % mod;
			cout << res << endl;
		}
	}
	return 0;
}