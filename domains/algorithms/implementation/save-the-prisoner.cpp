/*
  save-the-prisoner.cpp
  Save the Prisoner!
*/

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, s;
    cin >> n >> m >> s;
    int ans = (s + m % n - 1) % n;
    if (ans == 0) {
      ans = n;
    }
    cout << ans << endl;
  }
  return 0;
}