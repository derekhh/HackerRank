/*
  jumping-on-the-clouds-revisited.cpp
  Jumping on the Clouds: Revisited
*/

#include <iostream>
using namespace std;

int cloud[25];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> cloud[i];
  }
  int energy = 100, pos = 0;
  do {
    pos = (pos + k) % n;
    energy--;
    if (cloud[pos]) {
      energy -= 2;
    }
  } while (pos != 0);
  cout << energy << endl;
  return 0;
}