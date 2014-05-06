//randomness.cpp
//Randomness
//Daily Challenges - Week 1
//Author: derekhh

#include<cstdio>
#include<cstring>
using namespace std;

char s[75001];
const int MOD = 1000003;
const int BASE = 27;

struct Node {
	long long str;
	int cnt;
	Node* next;
};

Node* hash[MOD];

long long ans;

int n;
long long pow[10];

void modify(long long val, int delta)
{
	int mod = val % MOD;
	Node* cur = hash[mod];
	Node* tmp = NULL;

	bool newStr = true;
	while (cur != NULL)
	{
		if (cur->str == val)
		{
			cur->cnt += delta;
			if (cur->cnt == 0)
			{
				ans--;
				if (tmp == NULL)
					hash[mod] = hash[mod]->next;
				else
					tmp->next = cur->next;
			}
			return;
		}
		tmp = cur;
		cur = cur->next;
	}

	Node* node = new Node;
	node->str = val;
	node->cnt = delta;
	ans += delta;
	node->next = hash[mod];
	hash[mod] = node;
}

void init()
{
	for (int i = 0; i < MOD; i++)
		hash[i] = NULL;
	
	for (int i = 0; i < n; i++)
	{
		long long val = 0;
		for (int len = 1; len <= 9; len++)
		{
			if (i + len - 1 >= n) break;
			val = val * BASE + s[i + len - 1] - 'a' + 1;
			modify(val, 1);
		}
	}
}

void update(int p, char ch)
{
	for (int i = p - 8; i <= p; i++)
	{
		long long val = 0;
		for (int len = 1; len <= 9; len++)
		{
			if (i + len - 1 < 0 || i + len - 1 >= n) break;
			val = val * BASE + s[i + len - 1] - 'a' + 1;
			if (i + len - 1 >= p)
				modify(val, -1);
		}
	}
	s[p] = ch;
	for (int i = p - 8; i <= p; i++)
	{
		long long val = 0;
		for (int len = 1; len <= 9; len++)
		{
			if (i + len - 1 < 0 || i + len - 1 >= n) break;
			val = val * BASE + s[i + len - 1] - 'a' + 1;
			if (i + len - 1 >= p)
				modify(val, 1);
		}
	}
}

int main()
{
	int q;
	scanf("%d %d", &n, &q); getchar();
	scanf("%s", s);
	init();
	for (int i = 10; i <= n; i++)
		ans += n - i + 1;
	while (q--)
	{
		int p; char ch;
		scanf("%d %c", &p, &ch); getchar();
		update(p - 1, ch);
		printf("%lld\n", ans);
	}
	return 0;
}