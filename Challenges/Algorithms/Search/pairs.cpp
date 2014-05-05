//Pairs.cpp
//Pairs
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> s;

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
	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it)
		if (s.find(*it + k) != s.end()) ans++;
	cout << ans << endl;
	return 0;
}