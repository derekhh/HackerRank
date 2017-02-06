/*
  chocolate-feast.cpp
  Chocolate Feast
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c, m, numWrapper = 0, ans = 0;
    cin >> n >> c >> m;
    ans = n / c;
    numWrapper = n / c;
    while (numWrapper >= m) {
      ans += numWrapper / m;
      int tmp = numWrapper / m;
      numWrapper %= m;
      numWrapper += tmp;
    }
    cout << ans << endl;
  }
  return 0;
}