/*
  strange-advertising.cpp
  Viral Advertising
*/

#include <iostream>
using namespace std;

int f[51], g[51];

int main() {
  int n;
  cin >> n;
  f[1] = 5;
  g[1] = 2;
  long long sum = g[1];
  for (int i = 2; i <= n; i++) {
    f[i] = g[i - 1] * 3;
    g[i] = f[i] / 2;
    sum += g[i];
  }
  cout << sum << endl;
  return 0;
}