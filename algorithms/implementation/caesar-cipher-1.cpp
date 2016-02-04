// caesar-cipher-1.cpp
// Caesar Cipher
// Algorithms - Warmup
// Author: derekhh
// Jul 9, 2015

#include <iostream>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') cout << (char)((s[i] - 'A' + k) % 26 + 'A');
		else if (s[i] >= 'a' && s[i] <= 'z') cout << (char)((s[i] - 'a' + k) % 26 + 'a');
		else cout << s[i];
	}
	cout << endl;
	return 0;
}