/*
  plus-minus.cpp
  Plus Minus
*/

#include <iostream>
using namespace std;

int main() {
  int n, pos = 0, zero = 0, neg = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > 0) {
      pos++;
    } else if (tmp == 0) {
      zero++;
    } else {
      neg++;
    }
  }
  cout << 1.0 * pos / n << endl;
  cout << 1.0 * neg / n << endl;
  cout << 1.0 * zero / n << endl;
  return 0;
}