//emma-and-sum-of-products.cpp
//Emma and sum of products
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<iostream>
#include<cstring>
using namespace std;

const int MOD = 100003;

int a[30001], n;
int f[30001], g[30001];

void foo()
{
	f[0] = 1;  f[1] = a[1];
	for (int i = 2; i <= n;i++)
	{
		g[0] = 1;
		for (int j = 1; j <= i; j++)
			g[j] = (f[j] + (long long)f[j - 1] * a[i]) % MOD;
		memcpy(f, g, sizeof(g));
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	foo();
	int q;
	cin >> q;
	while (q--)
	{
		int k;
		cin >> k;
		cout << f[k] << endl;
	}
	return 0;
}