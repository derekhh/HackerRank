//closest-number.cpp
//Closest Number
//Weekly Challenges - Week 5
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x;
		cin >> a >> b >> x;
		if (b < 0)
		{
			//Now a ^ b \in [0,1)
			if (x != 1) cout << 0 << endl;
			else
			{
				if (a == 1) cout << 1 << endl;
				else cout << 0 << endl;
			}
		}
		else if (b == 0)
		{
			if (x != 1) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else
		{
			double tmp = pow(a, b);
			int lo = (int)(1.0 * tmp / x);
			double best = INT_MAX;
			int ans = 0;
			for (int i = lo - 5; i <= lo + 5; i++)
			{
				if (abs(1.0*i*x - tmp) < best)
					best = abs(1.0*i*x - tmp), ans = i;
			}
			cout << ans * x << endl;
		}
	}
	return 0;
}