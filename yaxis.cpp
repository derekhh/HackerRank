//yaxis.cpp
//Yaxis
//Addepar Hackathon
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;

struct Type
{
	int m, b;
};

bool operator < (Type t1, Type t2)
{
	return t1.b < t2.b;
}

Type l[200000];
set<int> s;
map<int, int> m;
int h[200000];

class FenwickTree
{
private:
	long long tree[200001];

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
		while (idx <= 200000)
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

FenwickTree a, b;
long long a1[200000], a2[200000];
long long b1[200000], b2[200000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
		cin >> l[i].m >> l[i].b;
	sort(l, l + n);
	for (int i = 0; i < n; i++)
		s.insert(l[i].m);
	int cnt = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		m.insert(make_pair(*it, cnt++));
	for (int i = 0; i < n; i++)
	{
		h[i] = m[l[i].m];
		a.set(h[i], 1);
		a1[i] = a.query(h[i] - 1);
		b1[i] = a.query(200000) - a.query(h[i]);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b.set(h[i], 1);
		a2[i] = b.query(h[i] - 1);
		b2[i] = b.query(200000) - b.query(h[i]);
	}
	long long ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += a1[i] * a2[i];
		ret += b1[i] * b2[i];
	}
	cout << ret << endl;
	return 0;
}