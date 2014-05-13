//diwali-lights.cpp
//Diwali Lights
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
using namespace std;

int modexp(int a, int b, int mod)
{
	long long ret = 1, tmp = a;
	while (b)
	{
		if (b & 1)
			ret = (ret * tmp) % mod;
		tmp = (tmp * tmp) % mod;
		b >>= 1;
	}
	return ret % mod;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int tmp = modexp(2, n, 100000);
		tmp--;
		if (tmp == -1) tmp = 99999;
		cout << tmp << endl;
	}
	return 0;
}