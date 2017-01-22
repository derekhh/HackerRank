/*
  kangaroo.cpp
  Kangaroo

  My first submission failed because I wrote

  if (dx % dv == 0 && dx / dv > 0)

  without adding the check "dv != 0" first.
*/

#include <iostream>
using namespace std;

int main() {
  int x1, v1, x2, v2;
  cin >> x1 >> v1 >> x2 >> v2;
  int dx = x1 - x2;
  int dv = v2 - v1;
  if (dv != 0 && dx % dv == 0 && dx / dv > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}