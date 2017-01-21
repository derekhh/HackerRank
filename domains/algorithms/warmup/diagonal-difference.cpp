/*
  diagonal-difference.cpp
  Diagonal Difference
*/

#include <iostream>
using namespace std;

const int MAXN = 1000;
int m[MAXN][MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    sum1 += m[i][i];
    sum2 += m[i][n - 1 - i];
  }
  cout << abs(sum1 - sum2) << endl;
  return 0;
}