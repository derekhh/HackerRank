// sum-of-absolutes.cpp
// Sum of Absolutes
// Author: derekhh
// Jul 6, 2015

#include <iostream>
using namespace std;

const int MAXN = 100000;
int sum[MAXN + 1];

int main()
{
	int n, q;
	cin >> n >> q;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		sum[i] = sum[i - 1] + val;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int val = sum[r] - sum[l - 1];
		if (val % 2 == 0)
			cout << "Even" << endl;
		else
			cout << "Odd" << endl;
	}
	return 0;
}