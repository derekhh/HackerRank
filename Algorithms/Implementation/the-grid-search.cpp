// the-grid-search.cpp
// The Grid Search
// Algorithms - Implementation
// Author: derekhh
// Jul 10, 2015

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MAXR = 1000, MAXC = 1000;
int big[MAXR][MAXC], small[MAXR][MAXC];

int main() {
	srand((unsigned int)(time(NULL)));
	int t;
	cin >> t;
	while (t--) {
		int br, bc, sr, sc;
		cin >> br >> bc;
		string str;
		for (int i = 0; i < br; i++) {
			cin >> str;
			for (int j = 0; j < bc; j++)
				big[i][j] = str[j] - '0';
		}
		cin >> sr >> sc;
		for (int i = 0; i < sr; i++) {
			cin >> str;
			for (int j = 0; j < sc; j++)
				small[i][j] = str[j] - '0';
		}
		bool exist = false;
		for (int i = 0; i + sr - 1 < br; i++) {
			for (int j = 0; j + sc - 1< bc; j++) {
				bool flag = true;
				for (int k = 0; k < 10; k++) {
					int x = rand() % sr, y = rand() % sc;
					if (small[x][y] != big[i + x][j + y]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					bool valid = true;
					for (int k = 0; k < sr; k++) {
						for (int l = 0; l < sc; l++) {
							if (small[k][l] != big[i + k][j + l]) {
								valid = false;
								break;
							}
						}
						if (!valid) break;
					}
					if (valid) {
						exist = true;
						goto end;
					}
				}
			}
		}
end:	cout << (exist ? "YES" : "NO") << endl;
	}
	return 0;
}