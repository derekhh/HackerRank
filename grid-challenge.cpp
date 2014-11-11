#include<iostream>
#include<algorithm>
using namespace std;

char ch[101][101];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				ch[i][j] = getchar();
			getchar();
		}
		for (int i = 0; i < n; i++)
			sort(ch[i], ch[i] + n);
		bool flag = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++)
				if (ch[j][i] > ch[j + 1][i])
					flag = false;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}