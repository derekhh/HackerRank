// devu-and-lucky-numbers.cpp
// Devu and Lucky Numbers
// Author: derekhh
// Jul 7, 2015

#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;
int f[MAXN + 1][MAXN + 1][MAXN + 1], cnt[MAXN + 1][MAXN + 1][MAXN + 1];
int pow10[301];

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	pow10[0] = 1;
	for (int i = 1; i <= x + y + z; i++)
		pow10[i] = ((long long) pow10[i - 1] * 10) % MOD;
	f[0][0][0] = 0;
	cnt[0][0][0] = 1;
	int ans = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			for (int k = 0; k <= z; k++) {
				if (i == 0 && j == 0 && k == 0) continue;
				if (i > 0) {
					cnt[i][j][k] = (cnt[i][j][k] + cnt[i - 1][j][k]) % MOD;
					f[i][j][k] = (f[i][j][k] + (long long) 4 * pow10[i + j + k - 1] * cnt[i - 1][j][k] + f[i - 1][j][k]) % MOD;
				}
				if (j > 0) {
					cnt[i][j][k] = (cnt[i][j][k] + cnt[i][j - 1][k]) % MOD;
					f[i][j][k] = (f[i][j][k] + (long long) 5 * pow10[i + j + k - 1] * cnt[i][j - 1][k] + f[i][j - 1][k]) % MOD;
				}
				if (k > 0) {
					cnt[i][j][k] = (cnt[i][j][k] + cnt[i][j][k - 1]) % MOD;
					f[i][j][k] = (f[i][j][k] + (long long) 6 * pow10[i + j + k - 1] * cnt[i][j][k - 1] + f[i][j][k - 1]) % MOD;
				}
				ans = (ans + f[i][j][k]) % MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}