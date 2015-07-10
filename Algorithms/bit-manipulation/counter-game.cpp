//counter-game.cpp
//Counter game
//Weekly Challenges - Week 8
//Author: derekhh

#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long n;
		cin >> n;
		int cnt = 0;
		while (n != 1)
		{
			int len = 0;
			unsigned long long tmp = n;
			while (tmp != 0) tmp /= 2, len++;
			unsigned long long a = (unsigned long long)1 << (len - 1);
			if (n == a) n /= 2;
			else n -= a;
			cnt++;
		}
		if (cnt % 2 == 0) cout << "Richard" << endl;
		else cout << "Louise" << endl;
	}
	return 0;
}