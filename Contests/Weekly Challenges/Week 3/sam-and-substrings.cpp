//sam-and-substrings.cpp
//Sam and sub-strings
//Weekly Challenges - Week 3
//Author: derekhh

#include<iostream>
#include<string>
using namespace std;

const int MOD = 1000000007;
string num;
int save[200001];

void init()
{
	save[1] = 1;
	for (int i = 2; i <= 200000; i++)
		save[i] = ((long long)save[i - 1] * 10 + 1) % MOD;
}

int main()
{
	init();
	string num;
	cin >> num;
	int n = (int)num.size();
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int digit = num[i - 1] - '0';
		ans = ((long long)digit * i * save[n - i + 1] + ans) % MOD;
	}
	cout << ans << endl;
	return 0;
}