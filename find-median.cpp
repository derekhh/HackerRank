//find-median.cpp
//Find the Median
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int a[1000002];

int partition(int ar[], int l, int r)
{
	int idx = rand() % (r - l + 1) + l;
	swap(ar[idx], ar[r]);
	int pivot = ar[r], cur = l;
	for (int i = l; i < r; i++)
		if (a[i] <= pivot)
			swap(a[i], a[cur++]);
	swap(ar[r], ar[cur]);
	return cur;
}

int quicksort(int ar[], int l, int r, int idx)
{
	if (l < r)
	{
		int m = partition(ar, l, r);
		if (idx == m - l + 1) return ar[m];
		else if (idx <= m - l)
			return quicksort(ar, l, m - 1, idx);
		else
			return quicksort(ar, m + 1, r, idx - (m - l + 1));
	}
	else
	{
		return ar[l];
	}
}

int main()
{
	srand((unsigned int)time(0));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << quicksort(a, 0, n - 1, (n + 1) / 2) << endl;
	return 0;
}