/*
  taum-and-bday.cpp
  Taum and B'day
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long b, w, x, y, z;
    cin >> b >> w >> x >> y >> z;
    if (x + z < y) {
      cout << b * x + w * (x + z) << endl;
    } else if (y + z < x) {
      cout << b * (y + z) + w * y << endl;
    } else {
      cout << b * x + w * y << endl;
    }
  }
  return 0;
}