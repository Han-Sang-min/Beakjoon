#include <bits/stdc++.h>
using namespace std;

int n;
int res;
int board[21][21];
int t_board[21][21];

void init_t_board()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t_board[i][j] = board[i][j];
}

void rote_board()
{
	int tmp[21][21];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = t_board[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t_board[i][j] = tmp[j][n - 1 - i];
}

void move_board(int dir)
{
	while (dir--) rote_board();
	for (int i = 0; i < n; i++)
	{
		int tmp[21] = {};
		int pos = 0;
		for (int j = 0; j < n; j++)
		{
			if (t_board[i][j] == 0) continue;
			else if (tmp[pos] == 0)
				tmp[pos] = t_board[i][j];
			else if (tmp[pos] == t_board[i][j])
				tmp[pos++] *= 2;
			else
				tmp[++pos] = t_board[i][j];
		}
		for (int j = 0; j < n; j++)
			t_board[i][j] = tmp[j];
	}
}

int find_big()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, t_board[i][j]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int i = 0; i < 1024; i++)
	{
		init_t_board();
		int dir = i;
		for (int j = 0; j < 5; j++)
		{
			move_board(dir % 4);
			dir /= 4;
		}
		res = max(res, find_big());
	}
	cout << res << "\n";
}