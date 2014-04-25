//ServiceLane.cpp
//Algorithms - Warmup
//Author: derekhh

#include<iostream>
using namespace std;

int width[100000];

int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> width[i];
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		int ans = 4;
		for (int i = l; i <= r; i++)
			if (width[i] < ans)
				ans = width[i];
		cout << ans << endl;
	}
}