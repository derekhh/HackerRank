// find-digits.cpp
// Find Digits
// Algorithms - Implementation
// Author: derekhh
// Jul 9, 2015

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		long long num;
		cin >> num;
		long long tmp = num;
		while (tmp) {
			int t = tmp % 10;
			if (t && num % t == 0) ans++;
			tmp /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}