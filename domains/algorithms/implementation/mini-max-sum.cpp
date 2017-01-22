/*
  mini-max-sum.cpp
  Mini-Max Sum
*/

#include <iostream>
using namespace std;

int main() {
  int a[5];
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }
  int minVal = a[0], maxVal = a[0];
  long long sum = a[0];
  for (int i = 1; i < 5; i++) {
    minVal = min(minVal, a[i]);
    maxVal = max(maxVal, a[i]);
    sum += a[i];
  }
  cout << sum - maxVal << " " << sum - minVal << endl;
  return 0;
}