//randomness_partial.cpp
//Randomness
//Daily Challenges - Week 1
//Author: derekhh

/*
	Complexity: O(QN\logN), pass the first 8 test cases.
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define nb nexta
#define head height
#define rank b

const int maxn = 75000;
char s[maxn];
int n, id[maxn], height[maxn], b[maxn], nexta[maxn];

bool cmp(const int& i, const int& j)
{
	return s[i] < s[j];
}

void SuffixSort()
{
	int i, j, k, h;
	for (i = 0; i < n; i++) id[i] = i;
	sort(id, id + n, cmp);
	for (i = 0; i < n; i++)
	{
		if (i == 0 || s[id[i]] != s[id[i - 1]])
			b[id[i]] = i;
		else b[id[i]] = b[id[i - 1]];
	}
	for (h = 1; h < n; h <<= 1)
	{
		for (i = 0; i < n; i++)
			head[i] = nexta[i] = -1;
		for (i = n - 1; i >= 0; i--)
		{
			if (id[i])
			{
				j = id[i] - h;
				if (j < 0) j += n;
				nexta[j] = head[b[j]];
				head[b[j]] = j;
			}
		}
		j = n - h;
		nexta[j] = head[b[j]];
		head[b[j]] = j;
		for (i = k = 0; i < n; i++)
			if (head[i] >= 0)
				for (j = head[i]; j >= 0; j = nexta[j])
					id[k++] = j;
		for (i = 0; i < n; i++)
			if (i>0 && id[i] + h < n&&id[i - 1] + h < n&&b[id[i]] == b[id[i - 1]] && b[id[i] + h] == b[id[i - 1] + h])
				nb[id[i]] = nb[id[i - 1]];
			else
				nb[id[i]] = i;
		for (i = 0; i < n; i++)
			b[i] = nb[i];
	}
}

void GetHeight()
{
	int i, j, h; height[0] = 0;
	for (i = 0; i < n; i++)
		rank[id[i]] = i;
	for (h = 0, i = 0; i < n;i++)
		if (rank[i]>0)
		{
			j = id[rank[i] - 1];
			while (s[i + h] == s[j + h])++h;
			height[rank[i]] = h;
			if (h>0) --h;
		}
}

int main()
{
	int q;
	scanf("%d%d", &n, &q);
	getchar();
	scanf("%s", s);
	long long tot = (n + 1) * (long long)n / 2;
	while (q--)
	{
		int p;
		char ch;
		getchar();
		scanf("%d %c", &p, &ch);
		s[p - 1] = ch;
		SuffixSort();
		GetHeight();
		long long sum = 0;
		for (int i = 0; i < n; i++)
			sum += height[i];
		cout << tot - sum << endl;
	}
	return 0;
}