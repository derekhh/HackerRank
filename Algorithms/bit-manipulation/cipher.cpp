//cipher.cpp
//Cipher
//Weekly Challenges - Week 10
//Author: derekhh

#include<stdio.h>

int a[1000000];

int main()
{
	int n, k;
	scanf("%d %d\n", &n, &k);
	int head = 0, curr = 0;
	for (int i = 0; i < n; i++)
	{
		if (i - head == k)
			curr ^= a[head++];
		a[i] = (getchar() - '0') ^ curr;
		printf("%d", a[i]);
		curr ^= a[i];
	}
	printf("\n");
	return 0;
}