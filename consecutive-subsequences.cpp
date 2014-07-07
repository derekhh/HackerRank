//consecutive-subsequences.cpp
//Consecutive Subsequences
//Weekly Challenges - Week 6
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

int cnt[100];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(cnt, 0, sizeof(cnt));
		int n, k, num, sum = 0;
		cin >> n >> k;
		cnt[0] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			sum += num;
			if (sum >= k) sum %= k;
			cnt[sum]++;
		}
		long long ret = 0;
		for (int i = 0; i < k; i++)
			ret += (long long)cnt[i] * (cnt[i] - 1) / 2;
		cout << ret << endl;
	}
	return 0;
}