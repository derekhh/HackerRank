#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &a, string &b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for (auto &e : unsorted)
        cin >> e;
    sort(unsorted.begin(), unsorted.end(), compare);
    for (auto &e : unsorted)
        cout << e << '\n';

    return 0;
}
