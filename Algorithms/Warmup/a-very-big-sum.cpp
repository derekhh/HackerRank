// a-very-big-sum.cpp
// A very big sum
// Algorithms - Warmup
// Author: derekhh
// Jul 9, 2015

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		sum += val;
	}
	cout << sum << endl;
	return 0;
}