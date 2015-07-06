//cut-the-sticks.cpp
//Cut the sticks
//Author: derekhh
//Jun 12, 2015

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int a[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int idx = n - 1;
	cout << n << endl;
	while (a[0] != 0)
	{
		for (int i = 0; i < n; i++)
		{
			a[i] -= a[idx];
			if (!a[i])
			{
				idx = i - 1;
				break;
			}
		}
		if (idx != -1)
			cout << idx + 1 << endl;
	}	
	return 0;
}