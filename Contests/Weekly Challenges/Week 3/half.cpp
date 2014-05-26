//half.cpp
//A stones game
//Weekly Challenges - Week 3
//Author: derekhh

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n % 2 == 1)
			printf("%d\n", 1);
		else
		{
			int cnt = 0;
			while (n) n >>= 1, cnt++;
			int finalsg = 1 ^ cnt, ans = -1;
			for (int i = 2; i <= cnt; i++)
			{
				if ((i ^ finalsg) <= i)
				{
					int a = (i ^ finalsg);
					int val = (1 << (i - 1)) - ((1 << a) - 1);
					if (val < (1 << (i - 2)))
						val = (1 << (i - 2));
					if (val < ans || ans == -1)
						ans = val;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}