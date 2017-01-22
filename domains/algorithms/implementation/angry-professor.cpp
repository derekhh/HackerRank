/*
  angry-professor.cpp
  Angry Professor
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      if (tmp <= 0) {
        cnt++;
      }
    }
    cout << (cnt < k ? "YES" : "NO") << endl;
  }
  return 0;
}