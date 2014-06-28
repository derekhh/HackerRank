//consistent-salaries.cpp
//Consistent Salaries
//Addepar Hackathon
//Author: derekhh

#include<iostream>
#include<set>
using namespace std;

set<int> s;

int e[200001], p[200001], t[200001];

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> e[i];
	for (int i = 2; i <= n; i++)
		if (e[i] > e[p[i]])
			s.insert(i);

	while (q--)
	{
		int a, b;
		cin >> a >> b;

		t[a] += b;

		if (a != 1)
		{
			if (e[a] + t[a] > e[p[a]])
				s.insert(a);
			else
				s.erase(a);
		}

		if (s.size() != 0)
			cout << "BAD" << endl;
		else
			cout << "GOOD" << endl;
	}
	return 0;
}