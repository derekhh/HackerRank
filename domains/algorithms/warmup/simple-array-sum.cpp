/*
  simple-array-sum.cpp
  Simple Array Sum
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    sum += tmp;
  }
  cout << sum << endl;
  return 0;
}
