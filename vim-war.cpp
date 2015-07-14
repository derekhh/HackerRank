// vim-war.cpp
// Vim War
// Week of Code 16
// Author: derekhh
// Jul 9, 2015

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100000;
const int MAXM = 20;
const int MOD = 1000000007;

int originalSkill[MAXN];
int f[1 << MAXM][MAXM + 1];

int modexp(int a, int b) {
	long long res = 1 % MOD, val = a % MOD;
	while (b) {
		if (b & 1)
			res = (res * val) % MOD;
		val = (val * val) % MOD;
		b >>= 1;
	}
	return (int)res;
}

int main() {
	int n, m;
	char str[MAXM + 1];
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		int val = 0;
		for (int j = 0; j < m; j++)
			val = val * 2 + (str[j] - '0');
		originalSkill[i] = val;
	}
	int target = 0, newm = 0;
	scanf("%s", str);
	for (int i = 0; i < m; i++) {
		if (str[i] == '1') {
			target = target * 2 + 1;
			newm++;
		}
	}

	for (int i = 0; i < n; i++) {
		int val = 0;
		bool flag = true;
		for (int j = m - 1; j >= 0; j--) {
			if (str[m - j - 1] == '1') {
				if (originalSkill[i] & (1 << j)) val = val * 2 + 1;
				else val *= 2;
			}
			else {
				if (originalSkill[i] & (1 << j)) {
					flag = false;
					break;
				}
			}
		}
		if (flag) f[val][newm]++;
	}

	for (int j = newm; j > 0; j--) {
		for (int i = 0; i < (1 << newm); i++) {
			f[i][j - 1] += f[i][j];
			int val = (i & (1 << (j - 1)));
			if (val == 0) {
				f[i | (1 << (j - 1))][j - 1] += f[i][j];
			}
		}
	}

	/*
	for (int i = 0; i < (1 << newm); i++) {
		printf("f[%d][0] = %d\n", i, f[i][0]);
	}
	*/
	
	int ans = 0;
	for (int i = 0; i < (1 << newm); i++) {
		int cnt = 0;
		for (int j = 0; j < newm; j++) {
			if (i & (1 << j)) 
				cnt++;
		}
		int val = modexp(2, f[i][0]);
		if (cnt % 2 == newm % 2) ans = (ans + val) % MOD;
		else ans = (ans - val + MOD) % MOD;
	}
	if (target == 0)
		printf("%d\n", (ans - 1 + MOD) % MOD);
	else
		printf("%d\n", ans);
	return 0;
}