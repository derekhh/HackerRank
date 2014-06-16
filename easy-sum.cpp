//easy-sum.cpp
//Easy sum
//Ad Inifinitum - June 14
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		long long sum = (long long)m * (m - 1) / 2;
		int quotient = n / m;
		int remainder = n % m;
		cout << sum * quotient + (long long)remainder * (remainder + 1) / 2 << endl;
	}
	return 0;
}