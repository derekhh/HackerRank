/*
  circular-array-rotation.cpp
  Circular Array Rotation
*/

#include <iostream>
using namespace std;

const int MAXN = 100000;
int a[MAXN];

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int idx;
    cin >> idx;
    int newIdx = ((idx - k) % n + n) % n;
    cout << a[newIdx] << endl;
  }
  return 0;
}