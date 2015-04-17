//superman-celebrates-diwali.cpp
//Superman Celebrates Diwali
//Weekly Challenges - Week 14 
//Author: derekhh

#include<iostream>
using namespace std;

const int MAXN = 1900, MAXH = 1900;

int f[MAXN][MAXH + 1], cnt[MAXN][MAXH + 1], g[MAXH + 1];

int main()
{
	int n, h, hl;
	cin >> n >> h >> hl;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int tmp;
			cin >> tmp;
			cnt[i][tmp]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		f[i][h] = cnt[i][h];
		if (f[i][h] > g[h])
			g[h] = f[i][h];
	}
	for (int j = h - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			if (j + hl <= h)
			{
				if (g[j + hl] > tmp) tmp = g[j + hl];
			}
			if (f[i][j + 1] > tmp) tmp = f[i][j + 1];
			f[i][j] = tmp + cnt[i][j];
			if (f[i][j] > g[j])
				g[j] = f[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (f[i][0] > ans)
			ans = f[i][0];
	cout << ans << endl;
	return 0;
}