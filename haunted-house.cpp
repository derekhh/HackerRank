//Haunted House
//Weekly Challenges - Week 15
//Author: derekhh
//May 26, 2015

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

const int MAXV = 300000 + 1;
vector<pair<int, int>> v;
int p[MAXV];

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++)
		v.push_back(make_pair(i, INT_MAX));
	sort(v.begin(), v.end());

	int tot = 0, prev = -1, ans = 0;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		if (v[i].second == INT_MAX)
		{
			if (prev != -1)
				tot -= p[prev];
			//cout << v[i].first << " " << tot << endl;
			if (tot >= v[i].first + 1 && v[i].first + 1 > ans)
				ans = v[i].first + 1;
			prev = v[i].first;
		}
		else
		{
			p[v[i].second]++;
			tot++;
		}
	}
	cout << ans << endl;
	return 0;
}