// sherlock-and-squares.cpp
// Sherlock and Squares
// Algorithms - Implementation
// Author: derekhh
// Jul 10, 2015

#include <iostream>
#include <cmath>
using namespace std;

int foo(int n) {
	return (int)(sqrt(1.0 * n));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << foo(b) - foo(a - 1) << endl;
	}
	return 0;
}