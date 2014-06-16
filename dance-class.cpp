//dance-class.cpp
//Dancing in Pairs
//Ad Infinitum - Math Programming Contest June'14
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
		long long num;
		cin >> num;
		long long val = (long long)sqrt(1.0*num);
		long long res = 0;
		for (long long i = val - 10; i <= val + 10; i++)
			if (i*i <= num)
				res = i;
		if (res % 2 == 1) cout << "odd" << endl;
		else cout << "even" << endl;
	}
	return 0;
}