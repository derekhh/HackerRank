/*
  the-time-in-words.cpp
  The Time in Words

  My first submission got WA because I didn't handle the case where M is in (30,
  40).
*/

#include <iostream>
using namespace std;

string s[21] = {"",        "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                "twenty"};

int main() {
  int h, m;
  cin >> h >> m;
  if (m == 0) {
    cout << s[h] << " o' clock" << endl;
  } else if (m < 15) {
    cout << s[m] << " minute" << (m == 1 ? "" : "s") << " past " << s[h]
         << endl;
  } else if (m == 15) {
    cout << "quarter past " << s[h] << endl;
  } else if (m <= 20) {
    cout << s[m] << " minutes past " << s[h] << endl;
  } else if (m < 30) {
    cout << "twenty " << s[m - 20] << " minutes past " << s[h] << endl;
  } else if (m == 30) {
    cout << "half past " << s[h] << endl;
  } else if (m < 40) {
    cout << "twenty " << s[40 - m] << " minutes to " << s[h + 1] << endl;
  } else if (m < 45) {
    cout << s[60 - m] << " minutes to " << s[h + 1] << endl;
  } else if (m == 45) {
    cout << "quarter to " << s[h + 1] << endl;
  } else {
    cout << s[60 - m] << " minute" << (m == 59 ? "" : "s") << " to " << s[h + 1]
         << endl;
  }
  return 0;
}