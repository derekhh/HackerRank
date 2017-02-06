/*
  beautiful-triplets.cpp
  Beautiful triplets

  My first submission got WA. I've created an array `h` of size that is exactly
  20001. Clearly this has some out-of-bound issues when checking h[v[i] + d] and
  h[v[i] + d + d].
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool h[21001];

int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
    h[num] = true;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (h[v[i] + d] && h[v[i] + d + d]) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}