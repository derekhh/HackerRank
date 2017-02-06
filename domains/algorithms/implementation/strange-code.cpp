/*
  strange-code.cpp
  Strange Counter
*/

#include <iostream>
using namespace std;

int main() {
  long long t;
  cin >> t;
  long long curCycleLen = 3;
  while (t >= curCycleLen) {
    t -= curCycleLen;
    curCycleLen *= 2;
  }
  if (t == 0) {
    cout << 1 << endl;
  } else {
    cout << curCycleLen - t + 1 << endl;
  }
  return 0;
}