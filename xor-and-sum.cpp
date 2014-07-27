//xor-and-sum.cpp
//Xor and Sum
//101 Hack July'14
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

string sa, sb;
int a[500000], b[500000];
int cnt[500000][2];

const int MOD = 1000000007;

int main()
{
	cin >> sa;
	cin >> sb;
	int la = sa.size(), lb = sb.size();
	for (int i = 0; i < la; i++)
		a[la - i - 1] = sa[i] - '0';
	for (int i = 0; i < lb; i++)
		b[lb - i - 1] = sb[i] - '0';

	cnt[0][0] = (b[0] == 0);
	cnt[0][1] = (b[0] == 1);
	for (int i = 1; i < lb + 314159; i++)
	{
		cnt[i][0] = cnt[i - 1][0] + (b[i] == 0);
		cnt[i][1] = cnt[i - 1][1] + (b[i] == 1);
	}

	long long ret = 0, cur = 0;
	for (int i = 0; i < lb + 314159; i++)
	{
		int cnt0, cnt1;
		if (i < 314159)
		{
			cnt0 = cnt[i][0] + 314159 - i;
			cnt1 = cnt[i][1];
		}
		else
		{
			cnt0 = 314159 + cnt[lb - 1][0] - cnt[i - 314159 - 1][0];
			cnt1 = cnt[lb - 1][1] - cnt[i - 314159 - 1][1];
		}

		long long sum0 = a[i] * cnt0;
		long long sum1 = (a[i] ^ 1) * cnt1;

		long long sum = sum0 + sum1;

		if (i == 0) cur = 1;
		else cur = (cur * 2) % MOD;
		
		long long tmp = (cur * sum) % MOD;
		ret = (ret + tmp) % MOD;
	}
	cout << ret << endl;
	return 0;
}