//handshake.cpp
//Handshake
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (long long)n * (n - 1) / 2 << endl;
	}
	return 0;
}