//building-a-list.cpp
//Building a List
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> vs;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vs.clear();
		int n;
		cin >> n;
		string str;
		cin >> str;
		for (int i = 1; i < (1 << n); i++)
		{
			string ans = "";
			for (int j = 0; j < n; j++)
				if (i&(1 << j))
					ans += str[j];
			vs.push_back(ans);
		}
		sort(vs.begin(), vs.end());
		for (int i = 0; i < (1 << n) - 1; i++)
			cout << vs[i] << endl;
	}
	return 0;
}