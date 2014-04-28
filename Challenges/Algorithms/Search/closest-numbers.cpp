//closest-numbers.cpp
//Closest Numbers
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int a[200000];

vector<int> ansv;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[i - 1] < ans)
		{
			ansv.clear();
			ans = a[i] - a[i - 1];
			ansv.push_back(a[i - 1]);
			ansv.push_back(a[i]);
		}
		else if (a[i] - a[i - 1] == ans)
		{
			ansv.push_back(a[i - 1]);
			ansv.push_back(a[i]);
		}
	}
	for (int i = 0; i < (int)ansv.size(); i++)
		cout << ansv[i] << " ";
	cout << endl;
	return 0;
}