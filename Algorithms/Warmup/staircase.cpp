// staircase.cpp
// Staircase
// Algorithms - Warmup
// Author: derekhh
// Jul 9, 2015

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++)
			cout << " ";
		for (int j = 0; j <= i; j++)
			cout << "#";
		cout << endl;
	}
	return 0;
}