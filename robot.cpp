//robot.cpp
//Robot
//Weekly Challenges - Week 10
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int MAXN = 500000;
int v[MAXN + 1], p[MAXN + 1];
long long sv[MAXN + 1], f[MAXN + 1];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> p[i];
		sv[i] = sv[i - 1] + v[i];
	}
	f[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = INT_MAX;
		for (int j = 1; j < i; j++)
			if (p[j] + j >= i)
				f[i] = min(f[i], f[j] + v[j]);
	}
	cout << sv[n] - f[n] << endl;
	return 0;
}