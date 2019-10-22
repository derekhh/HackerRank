//insertion-sort.cpp
//Insertion Sort Advanced Analysis
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<climits>
using namespace std;
typedef long long ll;
ll L[100000], R[100000], val[100000];
ll ans;

void merge(ll p, ll q, ll r)
{
	ll nL = 0, nR = 0, pL = 0, pR = 0;
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

void mergesort(ll l, ll r)
{
	if (l < r)
	{
		ll mid = (l + r) / 2;
		mergesort(l, mid);
		mergesort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		ll n;
		cin >> n;
		for (ll i = 0; i < n; i++)
			cin >> val[i];
		mergesort(0, n - 1);
		cout << ans << endl;
	}
	return 0;
}
