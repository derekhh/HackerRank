//countingsort4.cpp
//The Full Counting Sort
//Algorithms - Sorting
//Author: derekhh

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Pair
{
	Pair() {}
	Pair(int _val, string _str) : val(_val), str(_str) {}
	int val;
	string str;
};

vector<Pair> v;
vector<Pair> s;
int cnt[100];

int main()
{
	int n, val;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val >> str;
		Pair p(val, str);
		v.push_back(p);
		cnt[val]++;
	}

	int total = 0;
	for (int i = 0; i < 100; i++)
	{
		int tmp = cnt[i];
		cnt[i] = total;
		total += tmp;
	}

	s.resize(n);
	for (int i = 0; i < n; i++)
	{
		s[cnt[v[i].val]] = v[i];
		if (i < n / 2)
			s[cnt[v[i].val]].str = "-";
		cnt[v[i].val]++;
	}

	for (int i = 0; i < n; i++)
		cout << s[i].str << " ";
	cout << endl;
	return 0;
}