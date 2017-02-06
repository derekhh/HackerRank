/*
  kaprekar-numbers.cpp
  Modified Kaprekar Numbers
*/

#include <iostream>
using namespace std;

bool valid(long long num) {
  long long tmp = num;
  int d = 0;
  while (tmp) {
    tmp /= 10;
    d++;
  }
  tmp = num * num;
  string str = to_string(tmp);
  long long r = 0, l = 0;
  for (int i = str.size() - d; i < str.size(); i++) {
    r = r * 10 + str[i] - '0';
  }
  for (int i = 0; i < str.size() - d; i++) {
    l = l * 10 + str[i] - '0';
  }
  return l + r == num;
}

int main() {
  long long p, q;
  cin >> p >> q;
  int cnt = 0;
  for (int i = p; i <= q; i++) {
    if (valid(i)) {
      cout << i << " ";
      cnt++;
    }
  }
  if (cnt == 0) {
    cout << "INVALID RANGE" << endl;
  } else {
    cout << endl;
  }
  return 0;
}