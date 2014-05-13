//quicksort4.cpp
//Running Time of Quicksort
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
using namespace std;

int a[1000], b[1000], nQuickSortSwap, nInsertionSortSwap;

int partition(int ar[], int left, int right)
{
	int pivot = ar[right], idx = left;
	for (int i = left; i < right; i++)
		if (ar[i] < pivot)
		{
			nQuickSortSwap++;
			swap(ar[idx++], ar[i]);
		}
	swap(ar[idx], ar[right]);
	nQuickSortSwap++;
	return idx;
}

void quicksort(int ar[], int left, int right)
{
	if (left < right)
	{
		int p = partition(ar, left, right);
		quicksort(ar, left, p - 1);
		quicksort(ar, p + 1, right);
	}
}

void insertionsort(int ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		while (j > 0 && ar[j - 1] > ar[j])
		{
			swap(ar[j], ar[j - 1]);
			nInsertionSortSwap++;
			j--;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	quicksort(a, 0, n-1);
	insertionsort(b, n);
	cout << nInsertionSortSwap - nQuickSortSwap << endl;
	return 0;
}