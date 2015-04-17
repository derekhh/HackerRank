//worst-permutation.cpp
//Worst Permutation
//Weekly Challenges - Week 14
//Author: derekhh

#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100000;
int pos[MAXN + 1], p[MAXN], res[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		pos[num] = i;
		p[i] = num;
	}
	int cnt = 0;
	for (int i = n; i >= 1; i--)
	{
		if (pos[i] == n - i)
			continue;
		else
		{
			cnt++;
			int tmp = pos[i];
			pos[i] = n - i;
			pos[p[n - i]] = tmp;
			p[tmp] = p[n - i];
			p[n - i] = i;
			if (cnt == k) break;
		}
	}
	for (int i = 1; i <= n; i++)
		res[pos[i]] = i;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}