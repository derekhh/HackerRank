/*
  extra-long-factorials.cpp
  Extra Long Factorials
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];

int main() {
  int n;
  cin >> n;
  v[1].push_back(1);
  for (int i = 2; i <= n; i++) {
    int carry = 0;
    for (int j = 0; j < v[i - 1].size(); j++) {
      int tmp = v[i - 1][j] * i + carry;
      v[i].push_back(tmp % 10);
      carry = tmp / 10;
    }
    while (carry) {
      v[i].push_back(carry % 10);
      carry /= 10;
    }
  }
  for (int i = v[n].size() - 1; i >= 0; i--) {
    cout << v[n][i];
  }
  cout << endl;
  return 0;
}