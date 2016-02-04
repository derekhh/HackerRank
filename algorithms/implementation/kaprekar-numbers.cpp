// kaprekar-numbers.cpp
// Modified Kaprekar Numbers
// Algorithms - Implementation
// Author: derekhh
// Jul 10, 2015

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool foo(int num) {
	if (num == 1) return true;
	long long val = (long long) num * num;
	vector<int> v;
	long long t = 1;
	while (val) {
		v.push_back(val % 10);
		val /= 10;
		t *= 10;
	}
	reverse(v.begin(), v.end());
	long long curr = 0, rem = 0;
	for (int i = 0; i < v.size(); i++) {
		curr = curr * 10 + v[i];
		t /= 10;
		rem = (long long) num * num - curr * t;
		if (curr + rem == num && i == v.size() / 2 - 1)
			return true;
	}
	return false;
}

int main() {
	int p, q;
	cin >> p >> q;
	int cnt = 0;
	for (int i = p; i <= q; i++) {
		if (foo(i)) {
			cnt++;
			cout << i << " ";
		}
	}
	if (cnt == 0)
		cout << "INVALID RANGE";
	cout << endl;
}