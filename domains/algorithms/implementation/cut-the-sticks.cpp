/*
  cut-the-sticks.cpp
  Cut the sticks
*/

#include <iostream>
using namespace std;

int l[1000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  while (true) {
    int minVal = 1001;
    for (int i = 0; i < n; i++) {
      if (l[i] != 0) {
        minVal = min(minVal, l[i]);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (l[i] != 0) {
        l[i] -= minVal;
        cnt++;
      }
    }
    if (cnt == 0) {
      break;
    }
    cout << cnt << endl;
  }
  return 0;
}