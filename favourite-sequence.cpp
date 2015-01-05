//favourite-sequence.cpp
//Favorite sequence
//Weekly Challenges - Week 12
//Author: derekhh

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

vector<int> gr[1000001];
int indeg[1000001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int n;
	scanf("%d", &n);
	int maxval = -1;
	for (int i = 0; i < n; i++)
	{
		int len;
		scanf("%d", &len);
		int prev;
		for (int j = 0; j < len; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp > maxval) maxval = tmp;
			if (j != 0) gr[prev].push_back(tmp), indeg[tmp]++;
			prev = tmp;
		}
	}
	for (int i = 1; i <= maxval; i++)
	{
		if (indeg[i] == 0 && !gr[i].empty())
			pq.push(i);
	}
	while (!pq.empty())
	{
		int next = pq.top();
		printf("%d ", next);
		pq.pop();
		int sz = (int)gr[next].size();
		for (int i = 0; i < sz; i++)
		{
			int node = gr[next][i];
			indeg[node]--;
			if (indeg[node] == 0)
				pq.push(node);
		}
	}
	printf("\n");
	return 0;
}