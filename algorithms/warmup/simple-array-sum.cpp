// simple-array-sum.cpp
// Simple Array Sum
// Author: derekhh

#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
	}
	cout << sum << endl;
}