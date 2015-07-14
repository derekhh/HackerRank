// white-falcon-and-xor.cpp
// White Falcon and XOR
// Week of Code 16
// Author: derekhh
// Jul 10, 2015

#include <cstdio>
#include <cstring>
#include <cassert>
#include <ctime>
#include <map>
#include <iostream>
using namespace std;

const int MAXN = 8000;
const int MAXM = 6;
int a[MAXN], b[MAXN];
int parent[1 << MAXM];
int final;
int lazy;
int ans[MAXN];

int find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa != pb) parent[pa] = pb;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		ans[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		lazy = 1;
		final = 0;
		for (int i = 0; i < (1 << MAXM); i++) {
			parent[i] = i;
		}
		for (int i = 0; j + i < n; i++) {
			int pa = find(a[j + i]);
			int pb = find(b[j + i]);
			final ^= a[j + i];
			if (pa != pb) {
				for (int k = 0; k < (1 << MAXM); k++) {
					Union(k, k ^ a[j + i] ^ b[j + i]);
				}
			}
			else {
				lazy = (lazy << 1) % m;
			}
			if (find(final) == find(0)) {
				ans[i] += lazy;
				if (ans[i] >= m) ans[i] -= m;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
