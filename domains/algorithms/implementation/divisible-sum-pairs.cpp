/*
  divisible-sum-pairs.cpp
  Divisible Sum Pairs
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if ((v[i] + v[j]) % k == 0) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}