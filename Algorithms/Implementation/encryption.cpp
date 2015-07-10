//encryption.cpp
//Encryption
//Algorithms - Search
//Author: derekhh

#include<iostream>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int len = (int)str.size();
	int lb = (int)sqrt(1.0*len);
	int ub = (int)ceil(sqrt(1.0*len));
	int ans = INT_MAX;
	int r = 0, c = 0;
	for (int row = lb; row <= ub; row++)
		for (int col = row; col <= ub; col++)
			if (row * col >= len && row * col < ans)
			{
				ans = row * col;
				r = row;
				c = col;
			}
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
			if (j*c + i < len)
				cout << str[j*c + i]; 
		cout << " ";
	}
	cout << endl;
	return 0;
}