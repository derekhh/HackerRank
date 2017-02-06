/*
  acm-icpc-team.cpp
  ACM ICPC Team
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<bool> > v;

int main() {
  int n, m;
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(m);
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      v[i][j] = str[j] - '0';
    }
  }
  int maxTopic = 0, maxCnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cntTopic = 0;
      for (int k = 0; k < m; k++) {
        if (v[i][k] || v[j][k]) {
          cntTopic++;
        }
      }
      if (cntTopic > maxTopic) {
        maxTopic = cntTopic;
        maxCnt = 1;
      } else if (cntTopic == maxTopic) {
        maxCnt++;
      }
    }
  }
  cout << maxTopic << endl << maxCnt << endl;
  return 0;
}