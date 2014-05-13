//travel-around-the-world.cpp
//Travel around the world
//Weekly Challenges - Week 2
//Author: derekhh

#include<iostream>
using namespace std;

long long a[100001], b[100001], d[200001], sumd[200001];
int q[1000001], head, tail;

void enqueue(int idx)
{
	while (tail > head && sumd[q[tail - 1]] >= sumd[idx])
		tail--;
	q[tail++] = idx;
}

int main()
{
	int n;
	long long c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > c) a[i] = c;
	}
	bool valid = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		if (b[i] > c)
			valid = false;
	}
	if (!valid)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i] - b[i];
		d[i + n] = d[i];
	}
	sumd[0] = 0;
	for (int i = 1; i <= 2 * n; i++)
		sumd[i] = sumd[i - 1] + d[i];
	int ans = 0;
	head = tail = 0;

	for (int i = 1; i <= n; i++)
		enqueue(i);

	if (sumd[q[head]] >= sumd[0])
		ans++;
	if (sumd[q[head]] - sumd[0] < a[1] - c)
		valid = false;

	for (int i = 2; i <= n; i++)
	{
		if (head < tail && q[head] == i - 1)
			head++;

		enqueue(i + n - 1);

		if (sumd[q[head]] >= sumd[i - 1])
			ans++;
		if (sumd[q[head]] - sumd[i - 1] < a[i] - c)
			valid = false;
	}

	if (valid)
		cout << ans << endl;
	else
		cout << 0 << endl;
	return 0;
}