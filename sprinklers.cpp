// sprinklers.cpp
// Sprinklers
// Week of Code 16
// Author: derekhh
// Jul 8, 2015

#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 10000;
const int LOG_MAXN = 14;
int pos[MAXN + 1], f[MAXN + 1][LOG_MAXN], logs[MAXN + 1];
int n, bestval, bestq;
vector<int> bestans;

void rmq_init() {
	for (int i = 1; i <= n; i++)
		f[i][0] = pos[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[i][j - 1];
			if (i + (1 << (j - 1)) <= n)
				f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int main() {
	int j = 1;
	for (int i = 0; (1 << i) <= MAXN; i++)
		for (int k = 0; j <= MAXN && k < (1 << i); j++, k++)
			logs[j] = i;
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, s, q;
		scanf("%d%d%d%d", &n, &m, &s, &q);
		memset(pos, 0, sizeof(pos));
		for (int i = 0; i < m; i++) {
			int val;
			scanf("%d", &val);
			pos[val] = val;
		}
		rmq_init();
		bestval = INT_MAX;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			v.clear();
			int lb = 1;
			int ub = i + 1;
			int len = ub - lb + 1;
			int prev = max(f[lb][logs[len]], f[ub - (1 << logs[len]) + 1][logs[len]]);
			if (prev == 0) continue;
			v.push_back(prev);
			while (prev + i < n) {
				lb = prev + 1;
				ub = min(prev + 2 * i + 1, n);
				len = ub - lb + 1;
				int maxVal = max(f[lb][logs[len]], f[ub - (1 << logs[len]) + 1][logs[len]]);
				if (maxVal == 0) break;
				v.push_back(maxVal);
				prev = maxVal;
			}
			if (prev + i >= n) {
				int val = v.size() * s + q * i;
				if (val < bestval) {
					bestval = val;
					bestq = i;
					bestans = v;
				}
			}
		}
		printf("%d %d\n", (int) bestans.size(), bestq);
		for (int i = 0; i < bestans.size(); i++)
			printf("%d ", bestans[i]);
		printf("\n");
	}
	return 0;
}