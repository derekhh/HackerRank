//PSequences.cpp
//P-sequences
//Daily Challenges - Week 1
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MOD = 1000000007;
long long f[2][31623], g[2][31623], fSum[31623], fSumPrev[31623], gSum[31623], gSumPrev[31623];

int main()
{
	int n, p;
	cin >> n >> p;
	int sqrtVal = (int)sqrt(1.0*p);
	
	for (int i = 1; i <= sqrtVal; i++)
	{
		f[1][i] = 1;
		g[1][i] = (p / i - max(p / (i + 1), sqrtVal)) % MOD;
		fSum[i] = (fSum[i - 1] + f[1][i]) % MOD;
	}
	gSum[sqrtVal] = g[1][sqrtVal];
	for (int i = sqrtVal - 1; i >= 1; i--)
		gSum[i] = (gSum[i + 1] + g[1][i]) % MOD;

	int now = 1;
	for (int i = 2; i <= n; i++)
	{
		memcpy(fSumPrev, fSum, sizeof(fSum));
		memset(fSum, 0, sizeof(fSum));
		memcpy(gSumPrev, gSum, sizeof(gSum));
		for (int j = 1; j <= sqrtVal; j++)
		{
			f[1 - now][j] = (fSumPrev[sqrtVal] + gSumPrev[j]) % MOD;
			g[1 - now][j] = (fSumPrev[j] * (p / j - max(p / (j + 1), sqrtVal))) % MOD;
			fSum[j] = (fSum[j - 1] + f[1 - now][j]) % MOD;
		}
		
		memset(gSum, 0, sizeof(gSum));
		gSum[sqrtVal] = g[1 - now][sqrtVal];
		for (int j = sqrtVal - 1; j >= 1; j--)
			gSum[j] = (gSum[j + 1] + g[1 - now][j]) % MOD;

		now = 1 - now;
	}
	
	long long ans = fSum[sqrtVal];
	for (int i = 1; i <= sqrtVal; i++)
		ans = (ans + g[now][i]) % MOD;
	cout << ans << endl;
	return 0;
}