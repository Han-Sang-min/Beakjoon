#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[21][21];
int dice[6];

bool proc_dice(int dir)
{
	int t_dice[6];

	for (int i = 0; i < 6; i++)
		t_dice[i] = dice[i];
	switch (dir)
	{
	case 1:
		if (y + 1 == m) return 0;
		y += 1;
		t_dice[1] = dice[2];
		t_dice[2] = dice[3];
		t_dice[3] = dice[5];
		t_dice[5] = dice[1];
		break;
	case 2:
		if (y == 0) return 0;
		y -= 1;
		t_dice[1] = dice[5];
		t_dice[2] = dice[1];
		t_dice[3] = dice[2];
		t_dice[5] = dice[3];
		break;
	case 3:
		if (x == 0) return 0;
		x -= 1;
		t_dice[0] = dice[5];
		t_dice[2] = dice[0];
		t_dice[4] = dice[2];
		t_dice[5] = dice[4];
		break;
	case 4:
		if (x + 1 == n) return 0;
		x += 1;
		t_dice[0] = dice[2];
		t_dice[2] = dice[4];
		t_dice[4] = dice[5];
		t_dice[5] = dice[0];
		break;
	}
	for (int i = 0; i < 6; i++)
		dice[i] = t_dice[i];
	if (!board[x][y])
		board[x][y] = dice[5];
	else
	{
		dice[5] = board[x][y];
		board[x][y] = 0;
	}
	return 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = 0; i < k; i++)
	{
		int dir;
		cin >> dir;
		if (proc_dice(dir))
			cout << dice[2] << "\n";
	}
}