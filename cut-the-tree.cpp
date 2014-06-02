//cut-the-tree.cpp
//Cut the tree
//Weekly Challenges - Week 2
//Author: derekhh

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int value[100001], n, tot, best;
vector<vector<int> > v;
bool visited[100001];
int sum[100001];

int dfs(int node)
{
	int ret = 0;
	visited[node] = true;
	int sz = (int)v[node].size();
	for (int i = 0; i < sz; i++)
	{
		int next = v[node][i];
		if (!visited[next])
			ret += dfs(next);
	}
	return sum[node] = value[node] + ret;
}

int main()
{
	best = INT_MAX;
	tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
		tot += value[i];
	}
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (abs(tot - sum[i] - sum[i]) < best)
			best = abs(tot - sum[i] - sum[i]);
	cout << best << endl;
	return 0;
}