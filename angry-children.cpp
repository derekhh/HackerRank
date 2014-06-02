//angry-children.cpp
//Algorithms - Warmup
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

int x[100000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x, x + n);
	int ans = 2147483647;
	for (int i = k - 1; i < n; i++)
		if (x[i] - x[i - k + 1] < ans)
			ans = x[i] - x[i - k + 1];
	cout << ans << endl;
	return 0;
}