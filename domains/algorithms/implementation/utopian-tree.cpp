/*
  utopian-tree.cpp
  Utopian Tree
*/

#include <iostream>
using namespace std;

int l[61];

int main() {
  int t;
  cin >> t;
  l[0] = 1;
  for (int i = 1; i <= 60; i += 2) {
    l[i] = l[i - 1] * 2;
    l[i + 1] = l[i] + 1;
  }
  while (t--) {
    int n;
    cin >> n;
    cout << l[n] << endl;
  }
  return 0;
}