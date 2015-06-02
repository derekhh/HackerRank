//diagonal-queries.cpp
//Diagonal Queries
//Weekly Challenges - Week 15
//Author: derekhh
//May 28, 2015

#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_NODES = 524288;
const int MOD = 1000000007;

struct Node
{
	int left, right, lazyA, lazyD, sum;
};

Node tree[MAX_NODES];

void inc(int& a, int b)
{
	a = (a + b) % MOD;
}

int muldiv2(int a, int b)
{
	return static_cast<long long>(a)* b % MOD * 500000004LL % MOD;
}

void build_tree(int node, int a, int b)
{
	tree[node].lazyA = tree[node].lazyD = tree[node].sum = 0;
	tree[node].left = a;
	tree[node].right = b;

	if (a != b)
	{
		build_tree(node * 2, a, (a + b) / 2);
		build_tree(node * 2 + 1, (a + b) / 2 + 1, b);
	}
}

void lazyUpdate(int node)
{
	if (tree[node].lazyA != 0 || tree[node].lazyD != 0)
	{
		int a0 = tree[node].lazyA, d = tree[node].lazyD, a = tree[node].left, b = tree[node].right;

		int sum1 = static_cast<long long>(a0)* (b - a + 1) % MOD;
		int sum2 = muldiv2(static_cast<long long>(b - a)*d % MOD, b - a + 1);
		int sum = (sum1 + sum2) % MOD;
		inc(tree[node].sum, sum);

		if (tree[node].left != tree[node].right)
		{
			inc(tree[node * 2].lazyA, tree[node].lazyA);
			inc(tree[node * 2].lazyD, tree[node].lazyD);

			int a0_rightChild = (tree[node].lazyA + static_cast<long long>(tree[node].lazyD) * (tree[node * 2 + 1].left - tree[node * 2].left) % MOD) % MOD;

			inc(tree[node * 2 + 1].lazyA, a0_rightChild);
			inc(tree[node * 2 + 1].lazyD, tree[node].lazyD);
		}

		tree[node].lazyA = 0;
		tree[node].lazyD = 0;
	}
}

void update_tree(int node, int i, int j, int a0, int d)
{
	int a = tree[node].left, b = tree[node].right;
	if (a > j || b < i) return;

	lazyUpdate(node);

	if (a >= i && b <= j)
   	{
		int newa0 = (a0 + static_cast<long long>(a - i) * d % MOD) % MOD;
		inc(tree[node].lazyA, newa0);
		inc(tree[node].lazyD, d);
		return;
	}

	update_tree(node * 2, i, j, a0, d);
	update_tree(node * 2 + 1, i, j, a0, d);

	int l = max(a, i), r = min(b, j);
	int newa0 = (a0 + static_cast<long long>(l - i) * d % MOD) % MOD;

	int sum1 = static_cast<long long>(newa0)* (r - l + 1) % MOD;
	int sum2 = muldiv2(static_cast<long long>(r - l)*d % MOD, r - l + 1);
	int sum = (sum1 + sum2) % MOD;
	inc(tree[node].sum, sum);
}

int query_tree(int node, int i, int j)
{
	int a = tree[node].left, b = tree[node].right;

	if (a > j || b < i) return 0;

	lazyUpdate(node);

	if (a >= i && b <= j)
		return tree[node].sum;

	int sum1 = query_tree(node * 2, i, j);
	int sum2 = query_tree(node * 2 + 1, i, j);
	return (sum1 + sum2) % MOD;
}

int main()
{
	int n, m, q;
	scanf("%d%d%d\n", &n, &m, &q);
	build_tree(1, 1, n + m - 1);
	char cmd[10];
	while (q--)
	{
		scanf("%s", cmd);
		if (cmd[1] == 'c')
		{
			int c, d;
			scanf("%d%d\n", &c, &d);
			int newbase = static_cast<long long>(n)* d % MOD;
			update_tree(1, c, c + n - 1, newbase, MOD - d);
		}
		else if (cmd[1] == 'r')
		{
			int r, d;
			scanf("%d%d\n", &r, &d);
			update_tree(1, n - r + 1, n - r + m, d, d);
		}
		else if (cmd[1] == 's')
		{
			int x1, y1, x2, y2, d;
			scanf("%d%d%d%d%d\n", &x1, &y1, &x2, &y2, &d);
			int start = y1 + n - x2, end = y2 + n - x1;
			int width = min(x2 - x1, y2 - y1);
			int middle = end - start + 1 - width - width;
			if (width)
			{
				update_tree(1, start, start + width - 1, d, d);
				int newbase = static_cast<long long>(width)* d % MOD;
				update_tree(1, end - width + 1, end, newbase, MOD - d);
			}
			if (middle)
			{
				int newbase = static_cast<long long>(width + 1) * d % MOD;
				update_tree(1, start + width, end - width, newbase, 0);
			}
		}
		else if (cmd[1] == 'd')
		{
			int l, r;
			scanf("%d%d\n", &l, &r);
			printf("%d\n", query_tree(1, l, r));
		}
	}
	return 0;
}