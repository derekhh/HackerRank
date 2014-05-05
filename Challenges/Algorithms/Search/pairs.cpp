//Pairs.cpp
//Pairs
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

set<int> s;
//unordered_set<int> s;

int main()
{
	int n, k, val;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		s.insert(val);
	}
	int ans = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		int val = *it;
		if (s.find(val + k) != s.end()) ans++;
		if (s.find(val - k) != s.end()) ans++;
	}
	cout << ans / 2 << endl;
	return 0;
}