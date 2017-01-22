/*
  designer-pdf-viewer.cpp
  Designer PDF Viewer
*/

#include <iostream>
#include <string>
using namespace std;

int h[26];

int main() {
  string word;
  for (int i = 0; i < 26; i++) {
    cin >> h[i];
  }
  cin >> word;
  int maxHeight = -1;
  for (int i = 0; i < word.size(); i++) {
    maxHeight = max(maxHeight, h[word[i] - 'a']);
  }
  cout << word.size() * maxHeight << endl;
  return 0;
}