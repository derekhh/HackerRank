/*
  append-and-delete.cpp
  Append and Delete

  My first submission got WA since at that time I simply thought 'k >= minK'
  would ensure "Yes" since we can always delete the last character in an empty
  string to result in another empty string. At that time I haven't really
  considered the case between minK and maxK.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int k;
  cin >> k;
  int lcp = 0;
  for (int i = 0; i < min(s.size(), t.size()); i++) {
    if (s[i] == t[i]) {
      lcp++;
    } else {
      break;
    }
  }
  int minK = s.size() + t.size() - 2 * lcp;
  int maxK = s.size() + t.size();
  if (k >= maxK || (k >= minK && (k - minK) % 2 == 0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}