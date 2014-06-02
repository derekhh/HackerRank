//chocolate-feast.cpp
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
		int n, c, m;
		cin >> n >> c >> m;
		int ans = 0, cur = n / c, rem = 0;
		while (cur != 0)
		{
			ans += cur;
			int tmp = (cur + rem) / m;
			rem = cur + rem - tmp * m;
			cur = tmp;
		}
		cout << ans << endl;
	}
}