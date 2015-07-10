#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[100], p, q;
vector<int> v;

bool valid(int val)
{
	if (p <= val && val <= q) return true;
	return false;
}

int main()
{
	v.clear();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> p >> q;

	if (n != 1)
	{
		sort(a, a + n);

		for (int i = 0; i < n - 1; i++)
		{
			int diff = a[i + 1] - a[i];
			if (valid(a[i] + diff / 2)) v.push_back(a[i] + diff / 2);
			if (valid(a[i + 1] - diff / 2)) v.push_back(a[i + 1] - diff / 2);
		}
		v.push_back(p);
		v.push_back(q);
		sort(v.begin(), v.end());
		int sz = (int)v.size();
		int best = -1, bestval = 0;
		for (int i = 0; i < sz; i++)
		{
			int val = 2147483647;
			for (int j = 0; j < n; j++)
				if (abs(a[j] - v[i]) < val)
					val = abs(a[j] - v[i]);
			if (val > best)
			{
				best = val;
				bestval = v[i];
			}
		}
		cout << bestval << endl;
	}
	else
	{
		int val1 = abs(a[0] - p);
		int val2 = abs(a[0] - q);
		cout << (val1 >= val2 ? p : q) << endl;
	}
	return 0;
}