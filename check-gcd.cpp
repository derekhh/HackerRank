//check-gcd.cpp
//Check GCD
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 17, 2015

#include<iostream>
using namespace std;

int s[100000];

int gcd(int a,int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int val = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			if (s[i] % k == 0)
			{
				if (val == -1) val = s[i];
				else val = gcd(val, s[i]);
			}
		}
		cout << (val == k ? "YES" : "NO") << endl;
	}
	return 0;
}