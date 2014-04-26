//insertion-sort.cpp
//Insertion Sort Advanced Analysis
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<climits>
using namespace std;

int L[100000], R[100000], val[100000];
long long ans;

void merge(int p, int q, int r)
{
	int nL = 0, nR = 0, pL = 0, pR = 0;
	for (int i = p; i <= q; i++)
		L[nL++] = val[i];
	for (int i = q + 1; i <= r; i++)
		R[nR++] = val[i];
	L[nL] = INT_MAX; R[nR] = INT_MAX;
	for (int i = p; i <= r; i++)
	{
		if (L[pL] <= R[pR])
		{
			val[i] = L[pL];
			pL++;
		}
		else
		{
			val[i] = R[pR];
			ans += nL - pL;
			pR++;
		}
	}
}

void mergesort(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergesort(l, mid);
		mergesort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> val[i];
		mergesort(0, n - 1);
		cout << ans << endl;
	}
	return 0;
}