//stepping-stones-game.cpp
//Stepping Stones Game
//Ad Infinitum - Math Programming Contest August'14 
//Author: derekhh

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long tmp = (long long)sqrt(2.0 * n);
		if (tmp * (tmp + 1) == 2 * n)
			cout << "Go On Bob " << tmp << endl;
		else
			cout << "Better Luck Next Time" << endl;
	}
	return 0;
}