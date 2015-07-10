//reverse-game.cpp
//Reverse Game
//Ad Infinitum - Math Programming Contest August'14
//Author: derekhh

#include<iostream>
using namespace std;

int pos[100000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0, j = n - 1; i < n; i += 2, j--) pos[j] = i;
		for (int i = 1, j = 0; i < n; i += 2, j++) pos[j] = i;
		cout << pos[k] << endl;
	}
	return 0;
}