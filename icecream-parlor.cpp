//icecream-parlor.cpp
//Ice Cream Parlor
//Author: derekhh

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[10001];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> m;
		int n;
		cin >> n;
		for (int i = 1; i <= 10000; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int num;
			cin >> num;
			v[num].push_back(i);
		}
		for (int i = 1; i <= 10000; i++)
		{
			if (i != m - i)
			{
				if (!v[i].empty() && !v[m - i].empty())
				{
					cout << min(v[i][0], v[m - i][0]) << " " << max(v[i][0], v[m - i][0]) << endl;
					break;
				}
			}
			else
			{
				if (v[i].size() >= 2)
				{
					cout << v[i][0] << " " << v[i][1] << endl;
					break;
				}
			}
		}
	}
	return 0;
}