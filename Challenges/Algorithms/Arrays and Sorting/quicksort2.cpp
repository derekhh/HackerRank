//quicksort2.cpp
//QuickSort
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

int partition(int ar[], int left, int right)
{
	int b[1000], nb = 0;
	int pivot = ar[left];
	for (int i = left + 1; i <= right; i++)
		if (ar[i] <= pivot)
			b[nb++] = ar[i];
	b[nb++] = pivot;
	int idx = nb - 1 + left;
	for (int i = left + 1; i <= right; i++)
		if (ar[i] > pivot)
			b[nb++] = ar[i];
	
	for (int i = left; i <= right; i++)
		ar[i] = b[i - left];

	/*
	int pivot = ar[left], idx = left;
	swap(ar[left], ar[right]);
	for (int i = left; i < right; i++)
		if (ar[i] < pivot)
			swap(ar[idx++], ar[i]);
	swap(ar[idx], ar[right]);
	*/

	return idx;
}

void quicksort(int ar[], int left, int right)
{
	if (left < right)
	{
		int p = partition(ar, left, right);
		quicksort(ar, left, p - 1);
		quicksort(ar, p + 1, right);

		for (int i = left; i <= right; i++)
			cout << ar[i] << " ";
		cout << endl;
	}
}

int main()
{
	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	quicksort(a, 0, n - 1);
	return 0;
}