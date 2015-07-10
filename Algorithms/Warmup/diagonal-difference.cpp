//diagonal-difference.cpp
//Diagonal Difference
//Author: derekhh
//Jun 12, 2015

#include <iostream>
#include <cstdlib>
using namespace std;

int a[100][100];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		s1 += a[i][i];
		s2 += a[i][n - 1 - i];
	}
	cout << abs(s1 - s2) << endl;
	return 0;
}