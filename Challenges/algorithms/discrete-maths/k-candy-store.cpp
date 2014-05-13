//k-candy-store.cpp
//K Candy Store
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
using namespace std;

int f[1001][1001];

void init()
{
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		f[i][0] = f[i][i] = 1;
		for (int j = 1; j < i; j++)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % 1000000000;
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << f[k + 1][n - 1] << endl;
	}
	return 0;
}