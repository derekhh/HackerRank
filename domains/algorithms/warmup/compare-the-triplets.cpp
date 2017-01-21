/*
  compare-the-triplets.cpp
  Compare the Triplets
*/

#include <iostream>
using namespace std;

int main() {
  int a[3], b[3], sa = 0, sb = 0;
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < 3; i++) {
    if (a[i] > b[i]) {
      sa++;
    } else if (b[i] > a[i]) {
      sb++;
    }
  }
  cout << sa << " " << sb << endl;
  return 0;
}
