#include <bits/stdc++.h>
using namespace std;

int board[25][25];
int t_board[25][25];
int n, tmp, res;
vector <pair <int, int>> emty_pos;

void pnt()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << t_board[i][j] << " ";
		cout << "\n";
	}
}

int pow(int nu, int power)
{
	if (power == 0)
		return 1;
	return nu * pow(nu, power - 1);
}

void init_t_board()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t_board[i][j] = board[i][j];
}

int find_big()
{
	int ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ret < t_board[i][j])
				ret = t_board[i][j];
	return ret;
}

void rot_board()
{
	int tmp[25][25];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = t_board[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t_board[i][j] = tmp[j][n - 1 - i];
}

void move_board2()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (t_board[i][j] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (t_board[i][k] == 0)
					continue;
				if (t_board[i][j] == t_board[i][k])
				{
					t_board[i][j] *= 2;
					t_board[i][k] = 0;
					j = k;
					break;
				}
				else
					break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		emty_pos.clear();
		for (int j = 0; j < n; j++)
		{
			if (t_board[i][j] == 0)
				emty_pos.push_back({ i, j });
			else if (!emty_pos.empty())
			{
				t_board[emty_pos[0].first][emty_pos[0].second] = t_board[i][j];
				t_board[i][j] = 0;
				emty_pos.erase(emty_pos.begin());
				j--;
			}
		}
	}
}

void move_board1(int dir)
{
	if (dir == 0)
		move_board2();
	else if (dir == 1)
	{
		rot_board();
		move_board2();
		rot_board();
		rot_board();
		rot_board();
	}
	else if (dir == 2)
	{
		rot_board();
		rot_board();
		move_board2();
		rot_board();
		rot_board();
	}
	else if (dir == 3)
	{
		rot_board();
		rot_board();
		rot_board();
		move_board2();
		rot_board();
	}
}

int proc_dir(int dir)
{
	for (int i = 0; i < 5; i++)
	{
		move_board1(dir % 4);
		dir /= 4;
	}
	return find_big();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int i = 0; i < pow(4, 5); i++)
	{
		init_t_board();
		tmp = proc_dir(i);
		if (res < tmp)
		{
			//pnt();
			res = tmp;
		}
	}
	cout << res << "\n";
}