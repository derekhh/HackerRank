# Encryption

**Difficulty: Easy**
**Required Knowledge: None**
**Time Complexity: O(Len)**

This is a very basic implementation problem in which we only need to determine the number of rows and the number of columns in the square / rectangle. It is clearly stated that both the number of rows and the number of columns are not smaller than `floor(sqrt(len(word)))` and not larger than `ceil(sqrt(len(word)))`. Another constraint is that the number of rows is smaller than or equal to the number of columns. This gives us a total number of 4 choices so we just choose the one with the minimum area and then output the answer.

Code follows:

```C++
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