//upstairs.cpp
//Upstairs
//Addepar Hackathon
//Author: derekhh

#include<iostream>
using namespace std;

int a[100000];

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] > a[i - 1])
			sum += a[i] - a[i - 1];
	int best = sum, bestval = -2;
	for (int i = 0; i < n - 1; i++)
	{
		int sum_new = sum;
		if (i - 1 >= 0 && a[i] > a[i - 1])
			sum_new -= a[i] - a[i - 1];
		if (a[i + 1] > a[i])
			sum_new -= a[i + 1] - a[i];
		if (i + 2 < n && a[i + 2] > a[i + 1])
			sum_new -= a[i + 2] - a[i + 1];

		if (i - 1 >= 0 && a[i + 1] > a[i - 1])
			sum_new += a[i + 1] - a[i - 1];
		if (a[i] > a[i + 1])
			sum_new += a[i] - a[i + 1];
		if (i + 2 < n && a[i + 2] > a[i])
			sum_new += a[i + 2] - a[i];

		if (sum_new < best)
			best = sum_new, bestval = i;
	}
	cout << bestval + 1 << endl;
	return 0;
}