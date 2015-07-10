//countingsort2.cpp
//Counting Sort 2
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
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
		for (int j = 0; j < cnt[i]; j++)
			cout << i << " ";
	cout << endl;
	return 0;
}