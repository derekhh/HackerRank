//special-numbers.cpp
//Special Numbers
//Addepar Hackathon
//Author: derekhh

#include<iostream>
using namespace std;

int d[100001];
int f[100001];

void init()
{
	for (int i = 1; i <= 100000; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				if (j != i / j)
					d[i] += 2;
				else
					d[i] += 1;
			}
		}

		if (!f[d[i]]) f[d[i]] = i;
	}
}

int main()
{
	init();
	int n;
	cin >> n;
	int ret = 0;
	for (int i = 1; i <= 100000; i++)
		if (f[i] <= n)
			ret += f[i];
	cout << ret << endl;
	return 0;
}