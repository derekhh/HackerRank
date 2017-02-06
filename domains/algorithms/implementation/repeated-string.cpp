/*
  repeated-string.cpp
  Repeated String
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  long long n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      cnt++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n % s.size(); i++) {
    if (s[i] == 'a') {
      ans++;
    }
  }
  ans += (n / s.size()) * cnt;
  cout << ans << endl;
  return 0;
}