/*
  minimum-distances.cpp
  Minimum Distances
*/

#include <iostream>
using namespace std;

int num[100001];

int main() {
  int n;
  cin >> n;
  fill(num, num + 100000, -1);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (num[val] == -1) {
      num[val] = i;
    } else {
      if (ans == -1 || i - num[val] < ans) {
        ans = i - num[val];
      }
      num[val] = i;
    }
  }
  cout << ans << endl;
  return 0;
}