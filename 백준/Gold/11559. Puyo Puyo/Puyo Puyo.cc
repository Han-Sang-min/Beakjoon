#include <bits/stdc++.h>
using namespace std;

char board[15][10];
int ck[15][10];
char word;
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, -1, 0, 1 };
int cmb, cnt, flag = -1;

void init_ck()
{
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			ck[i][j] = 0;
}

void if_valide_pop(int x, int y)
{
	if (board[x][y] != word || ck[x][y] == 1)
		return;
	ck[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
		if_valide_pop(x + dir_x[i], y + dir_y[i]);
}

void chg_board()
{
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			if (ck[i][j] == 1)
				board[i][j] = '.';
}

void pop_bu()
{
	int flag = 0;

	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (board[i][j] != '.')
			{
				cnt = 0;
				word = board[i][j];
				init_ck();
				if_valide_pop(i, j);
				if (cnt >= 4)
				{
					flag = 1;
					chg_board();
				}
			}
		}
	}
	if (flag) cmb++;
}

void block_fall()
{
	char tmp[15][10];

	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			tmp[i][j] = '.';
	for (int i = 1; i <= 6; i++)
	{
		int idx = 1;
		for (int j = 1; j <= 12; j++)
		{
			if (board[13 - j][i] != '.')
			{
				tmp[13 - idx][i] = board[13 - j][i];
				idx++;
			}
		}
	}
	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			board[i][j] = tmp[i][j];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 12; i++)
		for (int j = 1; j <= 6; j++)
			cin >> board[i][j];
	while (flag != cmb)
	{
		flag = cmb;
		pop_bu();
		block_fall();
	}
	cout << cmb << "\n";
}