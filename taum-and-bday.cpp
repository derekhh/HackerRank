//taum-and-bday.cpp
//Taum and B'day
//Weekly Challenges - Week 13
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long b, w, x, y, z;
		cin >> b >> w >> x >> y >> z;
		long long ans1 = (b + w) * x + w * z;
		long long ans2 = (b + w) * y + b * z;
		long long ans3 = b * x + w * y;
		long long ans = min(min(ans1, ans2), ans3);
		cout << ans << endl;
	}
	return 0;
}