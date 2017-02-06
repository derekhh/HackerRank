/*
  bigger-is-greater.cpp
  Bigger is Greater
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int pos = -1;
    for (int i = s.size() - 1; i > 0; i--) {
      if (s[i] > s[i - 1]) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      cout << "no answer" << endl;
    } else {
      int minVal = 1000, maxIdx = -1;
      for (int i = pos; i < s.size(); i++) {
        if (s[i] > s[pos - 1]) {
          if (s[i] < minVal || (s[i] == minVal && i > maxIdx)) {
            minVal = s[i];
            maxIdx = i;
          }
        }
      }
      swap(s[pos - 1], s[maxIdx]);
      reverse(s.begin() + pos, s.end());
      cout << s << endl;
    }
  }
  return 0;
}