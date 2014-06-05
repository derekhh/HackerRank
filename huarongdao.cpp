//huarongdao.cpp
//Huarongdao
//Weekly Challenges - Week 2
//Author: derekhh

#include<cstdio>
#include<cstring>
using namespace std;

int nRow, nCol, k;

int board[200][200];
int dist[200][200][4][4];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

bool valid(int row, int col)
{
	return 0 <= row && row < nRow && 0 <= col && col < nCol && board[row][col] == 1;
}

struct Node
{
	int row, col, len;
	Node() {};
	Node(int r, int c, int l) : row(r), col(c), len(l) {};
};

Node q[50000];
bool visited[200][200];

void bfs(Node t, Node cc, int ret[])
{
	memset(visited, false, sizeof(visited));

	int head = 0, tail = 0;
	q[tail++] = t;
	visited[t.row][t.col] = true;

	for (int i = 0; i < 4; i++)
	{
		ret[i] = -2;
		int nx = cc.row + dx[i];
		int ny = cc.col + dy[i];
		if (t.row == nx && t.col == ny) ret[i] = 0;
		if (!valid(nx, ny)) ret[i] = -1;
	}

	while (head < tail)
	{
		Node tmp = q[head++];

		if (tmp.len == k - 1)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nr = tmp.row + dx[i];
			int nc = tmp.col + dy[i];
			int len = tmp.len + 1;
			if (valid(nr, nc) && (nr != cc.row || nc != cc.col) && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				Node next(nr, nc, len);
				for (int j = 0; j < 4; j++)
				{
					int nx = cc.row + dx[j];
					int ny = cc.col + dy[j];
					if (nr == nx && ny == nc)
					{
						ret[j] = len;
						break;
					}
				}
				q[tail++] = next;
			}
		}
	}

	for (int i = 0; i < 4; i++)
		if (ret[i] == -2)
			ret[i] = k;
}

void initdist()
{
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < nRow; i++)
		for (int j = 0; j < nCol; j++)
			if (board[i][j] != 0)
				for (int d = 0; d < 4; d++)
				{
					int emptyRow = i + dx[d];
					int emptyCol = j + dy[d];
					if (!valid(emptyRow, emptyCol)) continue;
					Node t(emptyRow, emptyCol, 0);
					Node cc(i, j, 0);
					bfs(t, cc, dist[i][j][d]);
				}
}

int dist2[200][200][4];
int cnt[200][200][4];

struct Node2
{
	int row, col, dir;
	Node2() {};
	Node2(int r, int c, int d) : row(r), col(c), dir(d) {};
};

Node2 swapBlocks(Node2 cc)
{
	int cc_nr = cc.row + dx[cc.dir];
	int cc_nc = cc.col + dy[cc.dir];
	int ndir;
	if (cc.dir <= 1) ndir = 1 - cc.dir;
	else ndir = 5 - cc.dir;
	Node2 ret(cc_nr, cc_nc, ndir);
	return ret;
}

const int MAXLEN = 500000;
Node2 q2[MAXLEN];

void spfa(Node cc, int start[4], Node target)
{
	memset(dist2, -1, sizeof(dist2));
	memset(cnt, 0, sizeof(cnt));

	int head = 0, tail = 0;
	for (int i = 0; i < 4; i++)
		if (start[i] != -1)
		{
			int ex = cc.row + dx[i];
			int ey = cc.col + dy[i];
			if (valid(ex, ey))
			{
				Node2 tmp(cc.row, cc.col, i);
				dist2[cc.row][cc.col][i] = start[i];
				cnt[cc.row][cc.col][i]++;
				q2[tail++] = tmp;
			}
		}

	while (head != tail)
	{
		Node2 tmp = q2[head];
		head = (head + 1) % MAXLEN;
		int tr = tmp.row, tc = tmp.col, td = tmp.dir;
		cnt[tr][tc][td]--;

		for (int i = 0; i < 4; i++)
		{
			if (i == td) continue;
			if (dist[tr][tc][td][i] == -1) continue;
			if (dist2[tr][tc][i] == -1 || (dist2[tr][tc][i] > dist2[tr][tc][td] + dist[tr][tc][td][i]))
			{
				dist2[tr][tc][i] = dist2[tr][tc][td] + dist[tr][tc][td][i];
				if (cnt[tr][tc][i] == 0)
				{
					q2[tail] = Node2(tr, tc, i);
					tail = (tail + 1) % MAXLEN;
					cnt[tr][tc][i]++;
				}
			}
		}

		Node2 swapped = swapBlocks(tmp);
		int r = swapped.row, c = swapped.col, d = swapped.dir;
		if (dist2[r][c][d] == -1 || (dist2[r][c][d] > dist2[tr][tc][td] + 1))
		{
			dist2[r][c][d] = dist2[tr][tc][td] + 1;
			if (cnt[r][c][d] == 0)
			{
				q2[tail] = Node2(r, c, d);
				tail = (tail + 1) % MAXLEN;
				cnt[r][c][d]++;
			}
		}
	}

	int ret = -1;
	for (int i = 0; i < 4; i++)
	{
		int val = dist2[target.row][target.col][i];
		if (val != -1 && (ret == -1 || val < ret))
			ret = val;
	}

	printf("%d\n", ret);
}

int main()
{
	int q;
	scanf("%d%d%d%d", &nRow, &nCol, &k, &q);
	for (int i = 0; i < nRow; i++)
		for (int j = 0; j < nCol; j++)
			scanf("%d", &board[i][j]);
	initdist();
	while (q--)
	{
		int ex, ey, sx, sy, tx, ty;
		scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
		ex--, ey--, sx--, sy--, tx--, ty--;

		Node t(ex, ey, 0);
		Node cc(sx, sy, 0);
		Node target(tx, ty, 0);
		int ret[4];
		bfs(t, cc, ret);

		spfa(cc, ret, target);
	}
	return 0;
}