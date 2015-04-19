//confused-gorilla.cpp
//Confused Gorilla
//Ad Infinitum 11 - Math Programming Contest
//By derekhh
//Apr 17, 2015

#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i <= n / 2; i++)
		{
			cout << i << " " << n - i << endl;
			if (i != n - i)
				cout << n - i << " " << i << endl;
		}
	}
	return 0;
}