//road-network.cpp
//Road Network
//Weekly Challenges - Week 2
//Author: derekhh

#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

const int maxn = 510;
const int MOD = 1000000007;

struct Edge {
	int v, c, next;
	Edge(){}
	Edge(int v, int c, int next) : v(v), c(c), next(next) {}
};

Edge edge[40010];

int n, m;
int head[maxn], E;

void add(int s, int t, int c) {
	edge[E] = Edge(t, c, head[s]);
	head[s] = E++;
	edge[E] = Edge(s, 0, head[t]);
	head[t] = E++;
}
int gap[maxn], dis[maxn], pre[maxn], cur[maxn];

int sap(int s, int t, int n)
{
	int i;
	for (i = 0; i <= n; i++) {
		dis[i] = gap[i] = 0;
		cur[i] = head[i];
	}
	gap[0] = n;
	int u = pre[s] = s, maxf = 0, aug = INT_MAX, v;
	while (dis[s] < n) {
	loop:
		for (i = cur[u]; ~i; i = edge[i].next) {
			v = edge[i].v;
			if (edge[i].c  && dis[u] == dis[v] + 1) {
				aug = min(aug, edge[i].c);
				pre[v] = u;
				cur[u] = i;
				u = v;
				if (u == t) {
					while (u != s) {
						u = pre[u];
						edge[cur[u]].c -= aug;
						edge[cur[u] ^ 1].c += aug;
					}
					maxf += aug;
					aug = INT_MAX;
				}
				goto loop;
			}
		}
		int d = n;
		for (i = head[u]; ~i; i = edge[i].next) {
			v = edge[i].v;
			if (edge[i].c && dis[v] < d) {
				d = dis[v];
				cur[u] = i;
			}
		}
		if (!(--gap[dis[u]]))
			break;
		++gap[dis[u] = d + 1];
		u = pre[u];
	}
	return maxf;
}

int ans[maxn][maxn], p[maxn];

bool mk[maxn];

void dfs(int u) {
	mk[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].next) {
		int v = edge[i].v;
		if (!mk[v] && edge[i].c)
			dfs(v);
	}
}

void solve(int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ans[i][j] = INT_MAX;
		}
		p[i] = 0;
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < E; j += 2) {
			edge[j].c += edge[j ^ 1].c;
			edge[j ^ 1].c = 0;
		}
		for (j = 0; j < n; j++) mk[j] = 0;
		int cut = sap(i, p[i], n);
		ans[i][p[i]] = ans[p[i]][i] = cut;
		dfs(i);
		for (j = i + 1; j < n; j++) if (mk[j] && p[i] == p[j])
			p[j] = i;
		for (j = 0; j < i; j++)
			ans[i][j] = ans[j][i] = min(cut, ans[p[i]][j]);
	}
}

int main() {
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		add(x, y, z);
		add(y, x, z);
	}
	solve(n);
	long long ret = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ret = (ret * ans[i][j]) % MOD;
	cout << ret << endl;
	return 0;
}