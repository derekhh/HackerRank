//lonely-integer.cpp
//Lonely Integer
//Algorithms - Search
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0, val;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		sum ^= val;
	}
	cout << sum << endl;
	return 0;
}