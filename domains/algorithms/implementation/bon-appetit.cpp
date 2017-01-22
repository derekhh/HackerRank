/*
  bon-appetit
  Bon Appétit
*/

#include <iostream>
using namespace std;

int main() {
  int n, k, sum = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    if (i != k) {
      sum += tmp;
    }
  }
  int b;
  cin >> b;
  if (b == sum / 2) {
    cout << "Bon Appetit" << endl;
  } else {
    cout << b - sum / 2 << endl;
  }
  return 0;
}