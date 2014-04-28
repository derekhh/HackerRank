//missing-numbers.cpp
//Missing Numbers
//Algorithms - Search
//Author: derekhh

#include<iostream>
using namespace std;

int a[20001], b[20001];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		a[val + 10000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int val;
		cin >> val;
		b[val + 10000]++;
	}
	for (int i = 0; i < 20001; i++)
		if (b[i] > a[i])
			cout << i - 10000 << " ";
	cout << endl;
	return 0;
}