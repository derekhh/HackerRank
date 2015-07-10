// song-of-pi.cpp
// Song of Pi
// Algorithms - Implementation
// Author: derekhh
// Jul 10, 2015

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const string PI = "31415926535897932384626433833";

int main() {
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	while (t--) {
		getline(cin, str);
		vector<int> v;
		istringstream in(str);
		string word;
		while (in >> word)
			v.push_back(word.size());
		bool flag = true;
		for (int i = 0; i < v.size(); i++) {
			if (PI[i] - '0' != v[i]) {
				flag = false;
				break;
			}
		}
		cout << "It's " << (flag ? "" : "not ") << "a pi song.\n";
	}
	return 0;
}