/*
  time-conversion.cpp
  Time Conversion
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  int h = (str[0] - '0') * 10 + (str[1] - '0');
  if (str[8] == 'A') {
    if (h < 12) {
      cout << str.substr(0, 8) << endl;
    } else {
      cout << "00" << str.substr(2, 6) << endl;
    }
  } else {
    if (h < 12) {
      h += 12;
    }
    cout << h << str.substr(2, 6) << endl;
  }
  return 0;
}