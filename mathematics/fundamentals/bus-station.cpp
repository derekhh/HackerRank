//bus-station.cpp
//Bus Station
//101 Hack July'14
//Author: derekhh

#include<iostream>
#include<set>
using namespace std;

int a[100000];
set<int> s;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int cur = a[0];
	s.insert(cur);
	for (int i = 1; i < n; i++)
	{
		cur += a[i];
		s.insert(cur);
	}

	for (set<int>::iterator it = s.begin(); it != s.end();++it)
	{
		if (cur % (*it) == 0)
		{
			bool flag = true;
			for (int j = 1; j <= cur / (*it); j++)
			{
				set<int>::iterator tt = s.find((*it) * j);
				if (tt == s.end())
				{
					flag = false;
					break;
				}
			}
			if (flag)
				cout << *it << " ";
		}
	}
	return 0;
}