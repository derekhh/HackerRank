//priyanka-and-toys.cpp
//Priyanka and Toys
//Weekly Challenges - Week 12
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

int w[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w, w + n);
	int ans = 1, prev = w[0];
	for (int i = 1; i < n; i++)
		if (w[i] - prev > 4)
			prev = w[i], ans++;
	cout << ans << endl;
	return 0;
}