/*
  equality-in-a-array.cpp
  Equalize the Array
*/

#include <cstring>
#include <iostream>
using namespace std;

int cnt[101];

int main() {
  int n;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }
  int maxCnt = 0;
  for (int i = 1; i <= 100; i++) {
    maxCnt = max(maxCnt, cnt[i]);
  }
  cout << n - maxCnt << endl;
  return 0;
}
