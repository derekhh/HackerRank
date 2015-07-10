//quicksort1.cpp
//QuickSort1 - Partition
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
using namespace std;

int a[1000], b[1000], nb;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] < a[0])
			b[nb++] = a[i];
	b[nb++] = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > a[0])
			b[nb++] = a[i];
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}