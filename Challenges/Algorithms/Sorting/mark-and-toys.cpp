//mark-and-toys.cpp
//Mark and Toys
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (sum >= k)
			break;
		ret++;
	}
	cout << ret << endl;
	return 0;
}