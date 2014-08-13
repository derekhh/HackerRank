//john-and-gcd-list.cpp
//John and GCD list
//Weekly Challenges - Week 8
//Author: derekhh

#include<iostream>
using namespace std;

int a[1000];

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << a[0] << " ";
		for (int i = 1; i < n; i++)
			cout << lcm(a[i - 1], a[i]) << " ";
		cout << a[n - 1] << endl;
	}
	return 0;
}