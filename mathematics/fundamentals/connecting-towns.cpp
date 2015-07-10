//connecting-towns.cpp
//Connecting Towns
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
		long long ans = 1;
		for (int i = 0; i < n - 1; i++)
		{
			int num;
			cin >> num;
			ans = (ans * num) % 1234567;
		}
		cout << ans << endl;
	}
	return 0;
}