//minimum-average-waiting-time.cpp
//Minimum Average Waiting Time
//Weekly Challenges - Week 6
//Author: derekhh

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Type
{
	int t, l;
};

struct cmp
{
	bool operator() (Type& a, Type& b)
	{
		return a.l > b.l;
	}
};

bool operator < (Type a, Type b)
{
	return a.t < b.t;
}

vector<Type> v;
priority_queue<Type, vector<Type>, cmp> pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, l;
		cin >> t >> l;
		Type tmp; tmp.t = t; tmp.l = l;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long cur_t = 0;
	long long tot = 0;
	int idx = 0;

	while (true)
	{
		int i;
		for (i = idx; i < n; i++)
		{
			if (v[i].t <= cur_t)
				pq.push(v[i]);
			else
			{
				idx = i;
				break;
			}
		}

		if (i == n) idx = n;

		if (!pq.empty())
		{
			Type tmp = pq.top();
			tot += cur_t + tmp.l - tmp.t;
			cur_t += tmp.l;
			pq.pop();
		}

		else
		{
			if (idx != n)
				cur_t = v[idx].t;
		}

		if (idx == n && pq.empty()) break;
	}

	cout << tot / n << endl;
	return 0;
}