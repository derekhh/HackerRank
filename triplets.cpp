//triplets.cpp
//Triplets
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
using namespace std;

const int MAXN = 100000;
int v[MAXN], h[MAXN];
set<int> s;
map<int, int> m;

class FenwickTree
{
private:
	long long tree[MAXN];

public:
	FenwickTree()
	{
		memset(tree, 0, sizeof(tree));
	}

	long long get(int idx)
	{
		return query(idx) - query(idx - 1);
	}

	void set(int idx, long long val)
	{
		long long curr = get(idx);
		update(idx, val - curr);
	}

	void update(int idx, long long val)
	{
		while (idx <= MAXN)
		{
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}

	long long query(int idx)
	{
		long long sum = 0;
		while (idx > 0)
		{
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
};

FenwickTree a, b, c;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.insert(v[i]);
	}
	int cnt = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		m.insert(make_pair(*it, cnt++));
	for (int i = 0; i < n; i++)
	{
		h[i] = m[v[i]];
		a.set(h[i], 1);
		b.set(h[i], a.query(h[i] - 1));
		c.set(h[i], b.query(h[i] - 1));
	}
	cout << c.query(MAXN) << endl;
	return 0;
}