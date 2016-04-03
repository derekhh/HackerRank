#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;
map<int, int> m;

int main() {
  int n;
  cin >> n;
  cout.setf(ios::fixed);
  cout.precision(1);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  double mean = accumulate(v.begin(), v.end(), 0) / (double)n;
  cout << mean << endl;
  sort(v.begin(), v.end());
  double median;
  if (n % 2 == 1)
    median = v[n / 2];
  else
    median = (v[n / 2 - 1] + v[n / 2]) / 2.0;
  cout << median << endl;
  for (int i = 0; i < n; i++) {
    auto it = m.find(v[i]);
    if (it != m.end())
      (it->second)++;
    else
      m.insert(make_pair(v[i], 1));
  }
  int mode, maxTimes = 0;
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second > maxTimes || (it->second == maxTimes && it->first < mode)) {
      mode = it->first;
      maxTimes = it->second;
    }
  }
  cout << mode << endl;
  double accum = 0.0;
  for (int i = 0; i < n; i++) {
    accum += (v[i] - mean) * (v[i] - mean);
  }
  double stdev = sqrt(accum / (double)n);
  cout << stdev << endl;
  return 0;
}