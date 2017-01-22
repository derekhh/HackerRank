/*
  beautiful-days-at-the-movies.cpp
  Beautiful Days at the Movies
*/

#include <iostream>
using namespace std;

int reverse(int x) {
  int ret = 0;
  while (x) {
    ret = ret * 10 + x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  int _i, _j, _k, cnt = 0;
  cin >> _i >> _j >> _k;
  for (int i = _i; i <= _j; i++) {
    int diff = abs(i - reverse(i));
    if (diff % _k == 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}