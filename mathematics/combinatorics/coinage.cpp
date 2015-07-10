//coinage.cpp
//Coinage
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int f[1001][4];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		memset(f, 0, sizeof(f));
		for (int i = 0; i <= min(1000, a); i++)
			f[i][0] = 1;
		for (int i = 0; i <= b; i++)
			for (int j = 0; j <= 1000; j++)
				if (j + i * 2 <= 1000)
					f[j + i * 2][1] += f[j][0];
		for (int i = 0; i <= c; i++)
			for (int j = 0; j <= 1000; j++)
				if (j + i * 5 <= 1000)
					f[j + i * 5][2] += f[j][1];
		for (int i = 0; i <= d; i++)
			for (int j = 0; j <= 1000; j++)
				if (j + i * 10 <= 1000)
					f[j + i * 10][3] += f[j][2];
		cout << f[n][3] << endl;
	}
	return 0;
}