/*
  jumping-on-the-clouds.cpp
  Jumping on the Clouds
*/

#include <cstring>
#include <iostream>
using namespace std;

int c[100], f[100];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  memset(f, 0, sizeof(f));
  for (int i = 1; i < n; i++) {
    if (c[i] == 1) {
      f[i] = -1;
    } else {
      if (i - 1 >= 0 && f[i - 1] != -1) {
        f[i] = f[i - 1] + 1;
      }
      if (i - 2 >= 0 && f[i - 2] != -1 && (f[i] == 0 || f[i - 2] + 1 < f[i])) {
        f[i] = f[i - 2] + 1;
      }
    }
  }
  cout << f[n - 1] << endl;
  return 0;
}