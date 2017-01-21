/*
  a-very-big-sum.cpp
  A Very Big Sum
*/

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long tmp, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    sum += tmp;
  }
  cout << sum << endl;
  return 0;
}