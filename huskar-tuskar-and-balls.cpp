//Huskar, Tuskar, and Balls
//Weekly Challenges - Week 15
//Author: derekhh
//May 27, 2015

#include<cstdio>
#include<vector>
using namespace std;

const int max_nodes = 200000;
const int log_max_nodes = 18;

int num_nodes, log_num_nodes, root;

// children[i] contains the children of node i
vector<int> children[max_nodes];
// A[i][j] is the 2^j-th ancestor of node i, or -1 if that ancestor does not exist
int A[max_nodes][log_max_nodes + 1];
// L[i] is the distance between node i and the root
int L[max_nodes], Q[max_nodes];

// floor of the binary logarithm of n
int lb(unsigned int n)
{
	if (n == 0)
		return -1;
	int p = 0;
	if (n >= 1 << 16) { n >>= 16; p += 16; }
	if (n >= 1 << 8) { n >>= 8; p += 8; }
	if (n >= 1 << 4) { n >>= 4; p += 4; }
	if (n >= 1 << 2) { n >>= 2; p += 2; }
	if (n >= 1 << 1) { p += 1; }
	return p;
}

void calcL()
{
	L[root] = 0;
	int head = 0, tail = 0;
	Q[tail++] = root;
	while (head < tail)
	{
		int node = Q[head++];
		for (int i = 0; i < static_cast<int>(children[node].size()); i++)
		{
			L[children[node][i]] = L[node] + 1;
			Q[tail++] = children[node][i];
		}
	}
}

int LCA(int p, int q)
{
	// ensure node p is at least as deep as node q
	if (L[p] < L[q])
		swap(p, q);

	// "binary search" for the ancestor of node p situated on the same level as q
	for (int i = log_num_nodes; i >= 0; i--)
		if (L[p] - (1 << i) >= L[q])
			p = A[p][i];

	if (p == q)
		return p;

	// "binary search" for the LCA
	for (int i = log_num_nodes; i >= 0; i--)
		if (A[p][i] != -1 && A[p][i] != A[q][i])
		{
			p = A[p][i];
			q = A[q][i];
		}

	return A[p][0];
}

int main()
{
	int num_nodes, q;
	scanf("%d%d", &num_nodes, &q);
	log_num_nodes = lb(num_nodes);

	A[0][0] = -1;
	root = 0;

	for (int i = 1; i < num_nodes; i++)
	{
		int p;
		scanf("%d", &p);
		p--;
		A[i][0] = p;
		children[p].push_back(i);
	}

	// precompute A using dynamic programming
	for (int j = 1; j <= log_num_nodes; j++)
		for (int i = 0; i < num_nodes; i++)
			if (A[i][j - 1] != -1)
				A[i][j] = A[A[i][j - 1]][j - 1];
			else
				A[i][j] = -1;

	// precompute L
	calcL();

	for (int i = 0; i < q; i++)
	{
		int h, t;
		scanf("%d%d", &h, &t);
		h--; t--;
		int lca_node = LCA(h, t);
		if (lca_node != t)
			printf("%d %d\n", L[h] + 1, L[t] - L[lca_node]);
		else
			printf("%d %d\n", L[h] - L[t], L[t] + 1);
	}
	return 0;
}