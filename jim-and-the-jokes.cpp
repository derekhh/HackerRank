#include<iostream>
#include<vector>
#include<set>
using namespace std;

long long cnt[38];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, d;
		cin >> m >> d;
		int tmp = d;
		bool valid = true;
		while (tmp)
		{
			if (tmp % 10 >= m) valid = false;
			tmp /= 10;
		}
		if (!valid) continue;
		int val = 0;
		tmp = d;
		int tt = 1;
		while (tmp)
		{
			val += (tmp % 10) * tt;
			tt *= m;
			tmp /= 10;
		}
		cnt[val]++;
	}
	long long ans = 0;
	for (int i = 0; i < 38; i++)
		ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}