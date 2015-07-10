//two-arrays.cpp
//Two arrays
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int a[1000], b[1000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + n, greater<int>());
		bool flag = true;
		for (int i = 0; i < n;i++)
			if (a[i] + b[i] < k)
			{
				flag = false;
				break;
			}
		cout << (flag ? "YES" : "NO") << endl;
	}
}