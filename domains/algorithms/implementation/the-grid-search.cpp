/*
  the-grid-search.cpp
  The Grid Search
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > g, p;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int R, C;
    cin >> R >> C;
    g.resize(R);
    for (int i = 0; i < R; i++) {
      string str;
      cin >> str;
      g[i].resize(C);
      for (int j = 0; j < C; j++) {
        g[i][j] = str[j] - '0';
      }
    }
    int r, c;
    cin >> r >> c;
    p.resize(r);
    for (int i = 0; i < r; i++) {
      string str;
      cin >> str;
      p[i].resize(c);
      for (int j = 0; j < c; j++) {
        p[i][j] = str[j] - '0';
      }
    }
    for (int i = 0; i < R - r + 1; i++) {
      for (int j = 0; j < C - c + 1; j++) {
        bool found = true;
        for (int k = 0; k < r; k++) {
          for (int l = 0; l < c; l++) {
            if (g[i + k][j + l] != p[k][l]) {
              found = false;
              goto e1;
            }
          }
        }
      e1:
        if (found) {
          cout << "YES" << endl;
          goto e2;
        }
      }
    }
    cout << "NO" << endl;
  e2:;
  }
  return 0;
}