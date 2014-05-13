//game-of-rotation.cpp
//Game Of Rotation
//Algorithms - Arrays and Sorting
//Author: derekhh

#include<iostream>
using namespace std;

int a[1000000];

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (long long) (i + 1) * a[i];

	long long best = ans;
	for (int i = 0; i < n; i++)
	{
		ans -= sum;
		ans += (long long) n * a[i];
		if (ans > best) best = ans;
	}
	cout << best << endl;
	return 0;
}