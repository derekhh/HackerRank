//angry-professor.cpp
//Angry Professor
//Author: derekhh
//Jun 12, 2015

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, cnt = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			if (val <= 0)
				cnt++;
		}
		cout << (cnt >= k ? "NO" : "YES") << endl;
	}
	return 0;
}