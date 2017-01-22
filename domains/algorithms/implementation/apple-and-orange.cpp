/*
  apple-and-orange.cpp
  Apple and Orange
*/

#include <iostream>
using namespace std;

int main() {
  int s, t, a, b, m, n;
  cin >> s >> t >> a >> b >> m >> n;
  int cntApple = 0, cntOrange = 0;
  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    int x = a + d;
    if (x >= s && x <= t) {
      cntApple++;
    }
  }
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    int x = b + d;
    if (x >= s && x <= t) {
      cntOrange++;
    }
  }
  cout << cntApple << endl << cntOrange << endl;
  return 0;
}