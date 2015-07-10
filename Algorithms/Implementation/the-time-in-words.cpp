// the-time-in-words.cpp
// The Time in Words
// Algorithms - Implementation
// Author: derekhh
// Jul 10, 2015

#include <iostream>
#include <string>
using namespace std;

string str[21] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                  "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

string output(int num) {
	if (num <= 20) {
		return str[num];
	}
	else if (num <= 29) {
		return str[20] + " " + str[num - 20];
	}
	else return "";
}

int main() {
	int h, m;
	cin >> h >> m;
	if (m == 0) {
		cout << output(h) << " o' clock" << endl;
	}
	else if (m < 15 || (m > 15 && m < 30)) {
		cout << output(m) << (m == 1 ? " minute" : " minutes") << " past " << output(h) << endl;
	}
	else if (m == 15) {
		cout << "quarter past " << output(h) << endl;
	}
	else if (m == 30) {
		cout << "half past " << output(h) << endl;
	}
	else if (m == 45) {
		cout << "quarter to " << output(h == 12 ? 1 : h + 1) << endl;	
	}
	else {
		cout << output(60 - m) << (m == 59 ? " minute" : " minutes") << " to " << output(h == 12 ? 1 : h + 1) << endl;
	}
	return 0;
}