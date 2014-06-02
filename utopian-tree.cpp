//utopian-tree.cpp
//Algorithms - Warmup
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
				ans *= 2;
			else
				ans += 1;
		}
		cout << ans << endl;
	}
	return 0;
}