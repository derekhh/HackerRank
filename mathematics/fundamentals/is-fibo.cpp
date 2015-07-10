//is-fibo.cpp
//Algorithms - Warmup
//Author: derekhh

#include<iostream>
using namespace std;

long long f[51];

void init()
{
	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= 50; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > 10000000000LL)
			break;
	}
}

int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		bool isFibo = false;
		for (int i = 0; i < 50;i++)
			if (f[i] == n)
			{
				isFibo = true;
				break;
			}
		if (isFibo)
			cout << "IsFibo" << endl;
		else
			cout << "IsNotFibo" << endl;
	}
	return 0;
}