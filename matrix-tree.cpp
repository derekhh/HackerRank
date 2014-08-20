//matrix-tree.cpp
//Matrix Tree
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<iostream>
#include<vector>
using namespace std;

int w[100001];
vector<int> v[100001];
bool visited[100001];
long long ans;

const int MOD = 1000000007;

void dfs(int root, int p)
{
	visited[root] = true;
	int sz = (int)v[root].size();
	for (int i = 0; i < sz; i++)
		if (!visited[v[root][i]])
			dfs(v[root][i], root);
	ans = (ans * (w[root] - w[p] + MOD)) % MOD;
}

int main()
{
	ans = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}