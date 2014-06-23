//game-of-thrones.cpp
//Game Of Thrones - I
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

int cnt[26];

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < (int)str.size(); i++)
		cnt[str[i] - 'a']++;
	int even = 0, odd = 0;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] % 2 == 0) even++;
		else odd++;
	}

	if (odd <= 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}