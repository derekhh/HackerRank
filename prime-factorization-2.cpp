//prime-factorization-2.cpp
//Prime factorization 2
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 17, 2015

#include<iostream>
using namespace std;

int sf[2000001], f[2000001];

int main()
{
	ios_base::sync_with_stdio(false);
	f[1] = 1;
	for (int i = 2; i <= 2000000; i++)
	{
		if (f[i] == 0)
		{
			f[i] = i;
			for (int j = i + i; j <= 2000000; j += i)
				if (f[j] == 0)
					f[j] = i;
		}
	}
	for (int i = 1; i <= 2000000;i++)
	{
		if (f[i] == i)
			sf[i] = i;
		else
			sf[i] = sf[i / f[i]] + f[i];
	}
	int t;
	cin >> t;
	long long ans = 0;
	while (t--)
	{
		int n;
		cin >> n;
		ans += sf[n];
	}
	cout << ans << endl;
	return 0;
}