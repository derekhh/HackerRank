/*
  flatland-space-stations.cpp
  Flatland Space Stations
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int val;
    cin >> val;
    v.push_back(val);
  }
  sort(v.begin(), v.end());
  int maxVal = v[0];
  for (int i = 0; i < m - 1; i++) {
    maxVal = max(maxVal, (v[i + 1] - v[i]) / 2);
  }
  maxVal = max(maxVal, n - 1 - v[m - 1]);
  cout << maxVal << endl;
  return 0;
}