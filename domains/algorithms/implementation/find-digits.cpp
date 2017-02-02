/*
  find-digits.cpp
  Find Digits
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int num;
    cin >> num;
    int tmp = num, ans = 0;
    while (tmp) {
      if ((tmp % 10 != 0) && (num % (tmp % 10) == 0)) {
        ans++;
      }
      tmp /= 10;
    }
    cout << ans << endl;
  }
  return 0;
}