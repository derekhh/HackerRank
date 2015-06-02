//a-knapsack-problem.cpp
//A Knapsack Problem
//Weekly Challenges - Week 15
//Author: derekhh
//May 29, 2015

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

vector<vector<int>> e;

const int MAXN = 2001;
int s[MAXN], v[MAXN], m, ans;
map<int, int> dp[MAXN], f;

void dfs(int root, int parent)
{
	for (int i = 0; i < (int)e[root].size(); i++)
		if (e[root][i] != parent)
			dfs(e[root][i], root);

	dp[root].clear();
	f.clear();

	if (s[root] <= m)
	{
		dp[root][s[root]] = v[root];
		f[s[root]] = v[root];
	}

	for (int i = 0; i < (int)e[root].size(); i++)
	{
		if (e[root][i] == parent) continue;
		for (auto j = dp[root].begin(); j != dp[root].end(); j++)
		{
			for (auto k = dp[e[root][i]].begin(); k != dp[e[root][i]].end(); k++)
			{
				if (j->first + k->first > m) break;
				f[j->first + k->first] = max(f[j->first + k->first], j->second + k->second);
			}
		}
		for (auto j = f.begin(); j != f.end(); j++)
		{
			while (true)
			{
				auto temp = j;
				temp++;
				if (temp == f.end() || temp->second > j->second)
					break;
				f.erase(temp);
			}
		}
		dp[root] = f;
	}
	   
	if (dp[root].size())
		ans = max(ans, dp[root].rbegin()->second);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		int n;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &s[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		e.clear();
		e.resize(n + 1);
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}