//chocolate-in-box.cpp
//Chocolate in Box
//Weekly Challenges - Week 7
//Author: derekhh

#include<iostream>
using namespace std;

int a[1000000];

int main()
{
	int n;
	cin >> n;
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		val ^= a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if ((val ^ a[i]) < a[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}