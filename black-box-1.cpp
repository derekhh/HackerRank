//black-box-1.cpp
//The Black Box
//Weekly Challenges - Week 8
//Author: derekhh

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> vv;

int main()
{
	int n;
	cin >> n;
	int sz = 0;
	while (n--)
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			v.push_back(num);
			sz++;
		}
		else
		{
			vector<int>::iterator pos = find(v.begin(), v.end(), -num);
			v.erase(pos);
			sz--;
		}
		vv.clear();
		vv = v;
		sort(vv.rbegin(), vv.rend());

		int sig = 1;
		while (sig <= vv[0])
			sig <<= 1;
		sig >>= 1;

		for (int t = 0; sig >= 1; sig >>= 1)
		{
			int i = t;
			while (i < sz && (vv[i] & sig) == 0) i++;
			if (i >= sz) continue;
			swap(vv[t], vv[i]);
			for (int j = 0; j < sz; ++j)
			{
				if (j != t && (vv[j] & sig) != 0)
					vv[j] = vv[j] ^ vv[t];
			}
			t++;
		}
		int result = 0;
		for (int q = 0; q < sz; q++)
			result ^= vv[q];
		printf("%d\n", result);
	}
	return 0;
}