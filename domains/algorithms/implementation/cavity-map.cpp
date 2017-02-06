/*
  cavity-map.cpp
  Cavity Map
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int> > v;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  int n;
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      v[i].push_back(str[j] - '0');
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && v[ni][nj] < v[i][j]) {
          cnt++;
        }
      }
      if (cnt == 4) {
        cout << 'X';
      } else {
        cout << v[i][j];
      }
    }
    cout << endl;
  }
  return 0;
}