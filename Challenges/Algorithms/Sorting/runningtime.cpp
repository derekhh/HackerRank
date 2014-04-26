//runningtime.cpp
//Running Time of Algorithms
//Algorithm - Sorting
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
	int cnt = 0;
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
		{
			ar[j] = ar[j - 1];
			cnt++;
		}
		ar[idx] = val;
	}
	cout << cnt << endl;
	return 0;
}