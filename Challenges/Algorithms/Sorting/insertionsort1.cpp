//insertionsort1.cpp
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
	int idx = 0, val = ar[s - 1];
	for (int i = 0; i< s - 1; i++)
		if (ar[i] < val && ar[i + 1] > val)
		{
			idx = i + 1;
			break;
		}
	for (int i = s - 1; i > idx; i--)
	{
		ar[i] = ar[i - 1];
		for (int j = 0; j < s; j++)
			cout << ar[j] << " ";
		cout << endl;
	}
	ar[idx] = val;
	for (int j = 0; j < s; j++)
		cout << ar[j] << " ";
	cout << endl;
	return 0;
}