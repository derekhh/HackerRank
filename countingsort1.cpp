//countingsort1.cpp
//Counting Sort 1
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

int cnt[100];

int main()
{
	int n, val;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		cnt[val]++;
	}
	for (int i = 0; i < 100; i++)
		cout << cnt[i] << " ";
	cout << endl;
	return 0;
}