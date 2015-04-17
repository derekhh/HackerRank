//number-list.cpp
//Number List
//Weekly Challenges - Week 14
//Author: derekhh

#include<iostream>
using namespace std;

int a[200000];
int b[200000], nb;

int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int p = 0, cnt = 0, nb = 0;
		while (p < n)
		{
			if (a[p] <= k) cnt++;
			else
			{
				if (cnt != 0) b[nb++] = cnt;
				cnt = 0;
			}
			p++;
		}
		if (cnt != 0) b[nb++] = cnt;

		long long res = 0;
		for (int i = 0; i < nb; i++)
			res += (long long)(b[i] + 1) * b[i] / 2;
		res = (long long)n * (n + 1) / 2 - res;
		cout << res << endl;
	}
	return 0;
}