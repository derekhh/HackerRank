//subtrees-and-paths.cpp
//Subtrees And Paths
//Weekly Challenges - Week 14
//Author: derekhh

//Reference:
//HLD: http://hzwer.com/2543.html

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define inf 0x7fffffff
#define N 100010 
#define M 200010

int n, q, cnt, sz;
int fa[N][21], deep[N], size[N], head[N];
int pos[N], belong[N], endpos[N];
bool vis[N];

struct data 
{ 
	int to, next; 
} e[M];

int tree[N * 4], lazy[N * 4];

void insert(int u, int v) 
{
	e[++cnt].to = v; e[cnt].next = head[u]; head[u] = cnt;
	e[++cnt].to = u; e[cnt].next = head[v]; head[v] = cnt;
}

void dfs1(int x) 
{
	size[x] = 1; vis[x] = 1;
	for (int i = 1; i <= 20; i++) 
	{
		if (deep[x] < (1 << i))break;
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = head[x]; i; i = e[i].next) 
	{
		if (vis[e[i].to])continue;
		deep[e[i].to] = deep[x] + 1;
		fa[e[i].to][0] = x;
		dfs1(e[i].to);
		size[x] += size[e[i].to];
	}
}

void dfs2(int x, int chain) {
	int k = 0; sz++;
	pos[x] = sz;
	belong[x] = chain;
	for (int i = head[x]; i; i = e[i].next) 
	{
		if (deep[e[i].to] > deep[x] && size[e[i].to] > size[k]) 
		{
			k = e[i].to;
		}
	}
	if (k == 0) {
		endpos[x] = sz;
		return;
	}
	dfs2(k, chain);
	for (int i = head[x]; i; i = e[i].next)
		if (deep[e[i].to] > deep[x] && k != e[i].to)
			dfs2(e[i].to, e[i].to);
	endpos[x] = sz;
}

int lca(int x, int y)
{
	if (deep[x] < deep[y])swap(x, y);
	int t = deep[x] - deep[y];
	for (int i = 0; i <= 20; i++)
		if (t&(1 << i))x = fa[x][i];
	for (int i = 20; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i])
		{
			x = fa[x][i]; y = fa[y][i];
		}
	}
	if (x == y)return x;
	else return fa[x][0];
}

void update(int node, int a, int b, int i, int j, int value)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (a != b)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (a > b || a > j || b < i) return;

	if (a >= i && b <= j) 
	{
		tree[node] += value;
		if (a != b) 
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}

	update(node * 2, a, (a + b) / 2, i, j, value);
	update(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query_tree(int node, int a, int b, int i, int j) {

	if (a > b || a > j || b < i) return -inf;

	if (lazy[node] != 0) 
	{
		tree[node] += lazy[node];

		if (a != b) 
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}

	if (a >= i && b <= j)
		return tree[node];

	int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
	int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);

	int res = max(q1, q2);

	return res;
}

int solvemx(int x, int f) 
{
	int mx = -inf;
	while (belong[x] != belong[f]) 
	{
		mx = max(mx, query_tree(1, 1, n, pos[belong[x]], pos[x]));
		x = fa[belong[x]][0];
	}
	mx = max(mx, query_tree(1, 1, n, pos[f], pos[x]));
	return mx;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		insert(a, b);
	}
	dfs1(1);
	dfs2(1, 1);
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		string str;
		cin >> str >> x >> y;
		if (str == "add")
		{
			update(1, 1, n, pos[x], endpos[x], y);
		}
		else
		{
			int t = lca(x, y);
			cout << max(solvemx(x, t), solvemx(y, t)) << endl;
		}
	}
	return 0;
}