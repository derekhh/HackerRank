/*
  service-lane.cpp
  Service Lane
*/

#include <iostream>
using namespace std;

int w[100000];

int main() {
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  while (t--) {
    int a, b, ans = 3;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
      ans = min(ans, w[i]);
    }
    cout << ans << endl;
  }
  return 0;
}