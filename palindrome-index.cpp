//palindrome-index.cpp
//Palindrome Index
//Weekly Challenges - Week 4
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

bool ispalin(string str)
{
	int i = 0, j = str.length() - 1;
	while (i < j)
	{
		if (str[i] != str[j]) return false;
		i++, j--;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		int i = 0, len = str.length(), j = len - 1;
		int ans = -1;
		while (i < j && str[i] == str[j]) i++, j--;
		if (i < j)
		{
			string str1 = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
			if (ispalin(str1)) ans = i;
			string str2 = str.substr(0, j) + str.substr(j + 1, str.length() - j - 1);
			if (ispalin(str2)) ans = j;
		}
		cout << ans << endl;
	}
	return 0;
}