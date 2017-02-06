/*
  sherlock-and-squares.cpp
  Sherlock and Squares
*/

#include <cmath>
#include <iostream>
using namespace std;

int f(int x) {
  // This function returns the number of square integers between [0, x].
  return (int)(sqrt(1.0 * x));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << f(b) - f(a - 1) << endl;
  }
  return 0;
}