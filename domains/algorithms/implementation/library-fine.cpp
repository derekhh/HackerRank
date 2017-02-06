/*
  library-fine.cpp
  Library Fine

  My first submission got WA because of a typo. I've mistyped 500 as 50.
*/

#include <iostream>
using namespace std;

int main() {
  int returnDay, returnMonth, returnYear;
  cin >> returnDay >> returnMonth >> returnYear;
  int expectDay, expectMonth, expectYear;
  cin >> expectDay >> expectMonth >> expectYear;
  if ((returnYear < expectYear) ||
      (returnYear == expectYear && returnMonth < expectMonth) ||
      (returnYear == expectYear && returnMonth == expectMonth &&
       returnDay <= expectDay)) {
    cout << 0 << endl;
  } else if (returnYear == expectYear && returnMonth == expectMonth &&
             returnDay > expectDay) {
    cout << 15 * (returnDay - expectDay) << endl;
  } else if (returnYear == expectYear) {
    cout << 500 * (returnMonth - expectMonth) << endl;
  } else {
    cout << 10000 << endl;
  }
  return 0;
}