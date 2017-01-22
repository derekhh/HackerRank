/*
  between-two-sets.cpp
  Between Two Sets

  All my first four submissions got WA because in the inner loop while
  testing whether a potential number is a common factor or not, I wrote

  for (int j = 0; j < n; j++)

  but actually array b contains m elements...

  The data of this problem is pretty weak. When calculating LCM of array
  a, the value could potentially overflow. But my earlier version which
  doesn't handle this overflow problem correctly also passed the judge.

  It's also trivial (and has been mentioned in the editorial) that after
  getting the GCD and LCM values. We only need to check whether a multiple
  of `lcmA` is a factor of `gcdB`. There is no need to involve the array
  any more.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int n, m, a[10], b[10];
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int lcmA = a[0];
  for (int i = 1; i < n; i++) {
    if (lcmA > 100) {
      lcmA = 101;
      break;
    }
    lcmA = lcm(lcmA, a[i]);
  }
  int gcdB = b[0];
  for (int i = 1; i < m; i++) {
    gcdB = gcd(gcdB, b[i]);
  }
  int cnt = 0;
  for (int i = lcmA; i <= gcdB; i += lcmA) {
    bool flag = true;
    for (int j = 0; j < m; j++) {
      if (b[j] % i != 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}