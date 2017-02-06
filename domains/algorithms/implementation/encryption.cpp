/*
  encryption.cpp
  Encryption
*/

#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  double tmp = (sqrt(1.0 * s.size()));
  int lb = (int)floor(tmp), ub = (int)ceil(tmp);
  int minArea = INT_MAX;
  int r, c;
  for (int i = lb; i <= ub; i++) {
    int tr = i;
    int tc = (int)(ceil(1.0 * s.size() / tr));
    if (tc >= lb && tc <= ub && tr * tc < minArea) {
      minArea = tr * tc;
      r = tr;
      c = tc;
    }
  }
  vector<vector<char> > v;
  v.resize(r);
  int cnt = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (cnt >= s.size()) {
        break;
      }
      v[i].push_back(s[cnt++]);
    }
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      if (i < v[j].size()) {
        cout << v[j][i];
      }
    }
    cout << ' ';
  }
  return 0;
}