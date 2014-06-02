//tutorial-intro.cpp
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
using namespace std;

int ar[1000];

int main()
{
	int v, n, ans;
	cin >> v >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		if (v == ar[i])
			ans = i;
	}
	cout << ans << endl;
}