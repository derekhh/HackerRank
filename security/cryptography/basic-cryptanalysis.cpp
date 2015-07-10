//basic-cryptanalysis.cpp
//Basic Cryptanalysis
//Algorithms - Discrete Mathematics
//Author: derekhh

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<string> vs[17];
vector<string> vs_lower[17];

struct Foo
{
	string str;
	int idx;
	int dicidx;
	Foo() {};
	Foo(string _str, int _idx) : str(_str), idx(_idx) {};
};

vector<Foo> v;
bool found;
int used[26];

bool cmp(Foo a, Foo b)
{
	return a.idx < b.idx;
}

void search(int cur, int rem)
{
	if (found) return;
	int tot = (int)v.size();
	if (cur == tot)
	{
		/*
		for (int i = 0; i < 26; i++)
		{
			if (used[i] != -1)
				cout << (char)(i + 'a') << "->" << (char)(used[i] + 'a') << endl;
		}
		*/

		for (int i = 0; i < tot; i++)
		{
			int len = (int)v[i].str.size();
			string plaintext = vs_lower[len][v[i].dicidx];
			v[i].str = plaintext;
		}
		sort(v.begin(), v.end(), cmp);
		for (int i = 0; i < tot; i++)
			cout << v[i].str << " ";
		cout << endl;
	}
	else
	{
		string encrypted = v[cur].str;
		int len = (int)encrypted.size();
		int sz = (int)vs[len].size();
		for (int i = 0; i < sz; i++)
		{
			int backup[26];
			memcpy(backup, used, sizeof(used));
			bool flag = true;
			int cnt = 0;
			for (int j = 0; j < len; j++)
			{
				if (used[encrypted[j] - 'a'] == -1)
				{
					used[encrypted[j] - 'a'] = vs_lower[len][i][j] - 'a';
					cnt++;
				}
				else
				{
					if (used[encrypted[j] - 'a'] != vs_lower[len][i][j] - 'a')
					{
						flag = false;
						break;
					}
				}
			}
			if (flag)
			{
				v[cur].dicidx = i;
				search(cur + 1, rem - cnt);
			}
			memcpy(used, backup, sizeof(used));
		}
	}
}

int main()
{
	ifstream fin("dictionary.lst");
	string str;
	int maxlen = 0;
	while (fin >> str)
	{
		int len = (int)str.size();
		vs[len].push_back(str);
		string tmp = "";
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				tmp += str[i] - 'A' + 'a';
			else
				tmp += str[i];
		}
		vs_lower[len].push_back(tmp);
	}
	int idx = 0;
	while (cin >> str)
		v.push_back(Foo(str, idx++));
	random_shuffle(v.begin(), v.end());
	memset(used, -1, sizeof(used));
	found = false;
	search(0, 26);
	fin.close();
	return 0;
}