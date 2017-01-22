/*
  sock-merchant.cpp
  Sock Merchant
*/

#include <cstring>
#include <iostream>
using namespace std;

int c[101];

int main() {
  int n, ans = 0;
  cin >> n;
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    c[tmp]++;
    if (c[tmp] == 2) {
      c[tmp] = 0;
      ans++;
    }
  }
  cout << ans << endl;
}