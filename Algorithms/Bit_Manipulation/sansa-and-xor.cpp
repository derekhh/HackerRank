//sansa-and-xor.cpp
//Sansa and XOR
//Weekly Challenges - Week 9
//Author: derekhh

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			long long times = (long long)(i + 1) * (n - i);
			if (times % 2 == 1)
				ans ^= num;
		}
		cout << ans << endl;
	}
	return 0;
}