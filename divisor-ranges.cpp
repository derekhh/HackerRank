//divisor-ranges.cpp
//Divisor Ranges
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 17, 2015

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 100000;
int pos[MAXN + 1], a[MAXN + 1], na;
long long cache[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		pos[val] = i;
	}
	memset(cache, -1, sizeof(cache));
	int q;
	cin >> q;
	while (q--)
	{
		int k;
		cin >> k;
		if (cache[k] != -1)
			cout << cache[k] << endl;
		else
		{
			na = 0;
			for (int i = k; i <= n; i += k)
				a[na++] = pos[i];
			sort(a, a + na);
			long long ans = 0;
			int curr = 1;
			for (int i = 1; i < na; i++)
			{
				if (a[i] != a[i - 1] + 1)
				{
					ans += static_cast<long long>(curr)* (curr + 1) / 2;
					curr = 1;
				}
				else
					curr++;
			}
			ans += static_cast<long long>(curr)* (curr + 1) / 2;
			cache[k] = ans;
			cout << ans << endl;
		}
	}
	return 0;
}