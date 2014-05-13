//countingsort3.cpp
//Counting Sort 3
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

int cnt[100];

int main()
{
	int n, val;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val >> str;
		cnt[val]++;
	}
	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += cnt[i];
		cout << sum << " ";
	}
	cout << endl;
	return 0;
}