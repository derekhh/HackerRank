/*
  fair-rations.cpp
  Fair Rations
*/

#include <iostream>
using namespace std;

int b[1000];

int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (b[i] % 2 == 1 && i + 1 < n) {
      b[i]++;
      b[i + 1]++;
      cnt += 2;
    }
  }
  if (b[n - 1] % 2 == 0) {
    cout << cnt << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}