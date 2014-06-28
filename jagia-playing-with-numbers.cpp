//jagia-playing-with-numbers.cpp
//Jaggu Playing with Balloons
//Weekly Challenges - Week 5
//Author: derekhh

#include<cstdio>
#include<string>
using namespace std;

long long tree[1000001];
int bitcount[2000000];

void init()
{
	for (int i = 0; i <= 2000000; i++)
		for (int j = 0; j < 31; j++)
			if (i&(1 << j))
				bitcount[i]++;
}

void update(int idx, int val)
{
	while (idx <= 1000000)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long read(int idx)
{
	long long sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int pos, int M, int plus)
{
	int N = 1000000;
	int sum = 0;
	for (int i = 1; i <= 50; i++)
	{
		int back = pos, j;
		for (j = 1; j <= 1000; j++)
		{
			int s, in = bitcount[pos];
			if (pos == 48576) break;
			update(pos, M);
			for (int k = 0;; k++)
			{
				s = pos + (1 << k);
				if (bitcount[s] <= in)
				{
					in = bitcount[s];
					pos = s;
					if (pos > N) break;
					update(pos, M);
				}
			}
			pos -= N;
		}

		sum += (1000 - j + 1) * M;
		pos = back + plus;
		if (pos > N) pos -= N;
	}

	update(48576, sum);
	update(48640, sum);
	update(49152, sum);
	update(65536, sum);
	update(131072, sum);
	update(262144, sum);
	update(524288, sum);
}

int main()
{
	int q;
	scanf("%d\n", &q);
	init();
	while (q--)
	{
		char ch;
		scanf("%c", &ch);
		if (ch == 'U')
		{
			int pos, M, plus;
			scanf("%d %d %d\n", &pos, &M, &plus);
			update(pos, M, plus);
		}
		else
		{
			int pos1, pos2;
			scanf("%d%d\n", &pos1, &pos2);
			long long sum1 = read(pos1 - 1);
			long long sum2 = read(pos2);
			printf("%lld\n", sum2 - sum1);
		}
	}
	return 0;
}