//VolleyballMatch.cpp
//Daily Challenges - Week 1
//Author: derekhh

#include<iostream>
using namespace std;

const int MOD = 1000000007;

bool TestValid(int a, int b)
{
	if (a < 25) return false;
	else if (a == 25) return b <= 23;
	else return b == a - 2;
}

long long powmod(long long a, int n)
{
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
	return res;
}

long long f[50][50];

void init()
{
	for (int i = 0; i < 50; i++)
		f[i][0] = f[i][i] = 1;
	for (int i = 2; i < 50; i++)
		for (int j = 1; j < i; j++)
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
}

int main()
{
	init();
	int a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);
	if (!TestValid(a, b))
		cout << 0 << endl;
	else
	{
		if (a > 25)
		{
			int diff = b - 24;
			long long ans = (powmod(2, diff) * f[48][24]) % MOD;
			cout << ans << endl;
		}
		else
		{
			cout << f[a + b - 1][b] << endl;
		}
	}
	return 0;
}