// extra-long-factorials.cpp
// Extra long factorials
// Algorithms - Warmup
// Author: derekhh
// Jul 9, 2015

#include <iostream>
using namespace std;

const int MAXLEN = 10000;
const int BASE = 10000;

struct BigInt {
	int num[MAXLEN];
	int len;
};

BigInt mul(BigInt a, int b) {
	BigInt c;
	int carry = 0, nc = 0;
	for (int i = 0; i < a.len; i++) {
		int val = a.num[i] * b;
		c.num[nc++] = (carry + val) % BASE;
		carry = (carry + val) / BASE;
	}
	if (carry)
		c.num[nc++] = carry;
	c.len = nc;
	return c;
}

void output(BigInt a) {
	printf("%d", a.num[a.len - 1]);
	for (int i = a.len - 2; i >= 0; i--)
		printf("%04d", a.num[i]);
}

int main() {
	BigInt ret;
	ret.num[0] = 1;
	ret.len = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		ret = mul(ret, i);
	output(ret);
	printf("\n");
	return 0;
}