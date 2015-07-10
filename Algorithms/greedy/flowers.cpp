//flowers.cpp
//Flowers
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<functional>
#include<algorithm>
using namespace std;

int c[100];

int main()
{
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n, greater<int>());
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		ans += c[i] * (cnt / k + 1);
		cnt++;
	}
	cout << ans << endl;
	return 0;
}