//sherlock-and-anagrams.cpp
//Sherlock and Anagrams
//Weekly Challenges - Week 13
//Author: derekhh

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

map<string, int> m;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		m.clear();
		string s;
		cin >> s;
		int len = (int)s.size();
		for (int i = 0; i < len; i++)
		{
			for (int l = 1; i + l - 1 < len; l++)
			{
				string t = s.substr(i, l);
				sort(t.begin(), t.end());
				m[t]++;
			}
		}
		long long ans = 0;
		for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
			ans += (long long)(it->second) * (it->second - 1) / 2;
		cout << ans << endl;
	}
	return 0;
}