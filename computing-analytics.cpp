//computing-analytics.cpp
//Computing Analytics
//Addepar Hackathon
//Author: derekhh

#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> l[100001], r[100001];
unordered_set<int> leftMinusOne[100001];

int main()
{
	int n, c, q;
	cin >> n >> c >> q;
	for (int i = 0; i < c; i++)
	{
		int a, b;
		cin >> a >> b;
		l[b].insert(a);
		leftMinusOne[b].insert(a - 1);
		r[a].insert(b);
	}

	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);

		bool found = false;
		if (r[a].find(b) != r[a].end())
		{
			found = true;
			goto end;
		}

		// merge
		for (unordered_set<int>::iterator it = r[a].begin(); it != r[a].end(); ++it)
		{
			if (leftMinusOne[b].find(*it) != leftMinusOne[b].end())
			{
				found = true;
				goto end;
			}
		}

		// [a, c] and [b+1, c]

		for (unordered_set<int>::iterator it = r[a].begin(); it != r[a].end(); ++it)
		{
			if (r[b + 1].find(*it) != r[b + 1].end())
			{
				found = true;
				goto end;
			}
		}

		// [c, a-1] and [c,b]
		for (unordered_set<int>::iterator it = l[a - 1].begin(); it != l[a - 1].end(); ++it)
		{
			if (l[b].find(*it) != l[b].end())
			{
				found = true;
				goto end;
			}
		}
	end:
		cout << (found ? "YES" : "NO") << endl;
	}
	return 0;
}