//insertionsort2.cpp
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
using namespace std;

int ar[1000];

int main()
{
	int s;
	cin >> s;
	for (int i = 0; i < s; i++)
		cin >> ar[i];
	for (int i = 1; i < s; i++)
	{
		int idx = i, val = ar[i];
		for (int j = 0; j < i; j++)
			if (val < ar[j])
			{
				idx = j;
				break;
			}
		for (int j = i; j > idx; j--)
			ar[j] = ar[j - 1];
		ar[idx] = val;
		for (int j = 0; j < s; j++)
			cout << ar[j] << " ";
		cout << endl;
	}
	return 0;
}