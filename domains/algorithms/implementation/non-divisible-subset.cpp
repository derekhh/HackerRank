/*
  non-divisible-subset.cpp
  Non-Divisible Subset
*/

#include <cstring>
#include <iostream>
using namespace std;

int mod[100];

int main() {
  int n, k;
  cin >> n >> k;
  memset(mod, 0, sizeof(mod));
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    mod[num % k]++;
  }
  int ans = 0;
  for (int i = 0; i <= k / 2; i++) {
    if (k - i != i && i != 0) {
      ans += max(mod[i], mod[k - i]);
    } else {
      ans += min(1, mod[i]);
    }
  }
  cout << ans << endl;
  return 0;
}