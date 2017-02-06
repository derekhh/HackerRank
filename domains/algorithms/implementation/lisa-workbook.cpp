/*
  lisa-workbook.cpp
  Lisa's Workbook
*/

#include <iostream>
using namespace std;

int main() {
  int n, k, t, page = 1, ans = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    for (int j = 1; j <= t; j++) {
      int page_no = (j - 1) / k + page;
      if (j == page_no) {
        // cout << i << " " << page_no << endl;
        ans++;
      }
    }
    page += (t - 1) / k + 1;
  }
  cout << ans << endl;
  return 0;
}