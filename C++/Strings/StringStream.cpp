#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
    vector<int> v1;
    int i=0;
    stringstream ss;
    ss <<str<< ".";
    int a;
    char ch;
    ss>>a>>ch;
    v1.push_back(a);    
    while(ch==','){
        ss>>a>>ch;
        v1.push_back(a);
        //i++;
    }
    return v1;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
1
