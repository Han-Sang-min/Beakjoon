#include <bits/stdc++.h>
using namespace std;

int nt_book[45][45];
int stick[15][15];
int n, m, k;
int st_x, st_y;

void init_stick(int x, int y)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> stick[i][j];
}

bool tt_ntbook2(int x, int y)
{
	for (int i = 0; i < st_x; i++)
		for (int j = 0; j < st_y; j++)
			if (nt_book[x + i][y + j] == 1 && stick[i][j] == 1)
				return 0;
	for (int i = 0; i < st_x; i++)
		for (int j = 0; j < st_y; j++)
			if (stick[i][j] == 1)
				nt_book[x + i][y + j] = stick[i][j];
	return 1;
}

bool tt_ntbook1()
{
	for (int x = 0; x <= n - st_x; x++)
		for (int y = 0; y <= m - st_y; y++)
			if (tt_ntbook2(x, y))
				return 1;
	return 0;
}

void turn_stick()
{
	int tmp[15][15];

	for (int i = 0; i < st_x; i++)
		for (int j = 0; j < st_y; j++)
			tmp[i][j] = stick[i][j];
	swap(st_x, st_y);
	for (int i = 0; i < st_x; i++)
		for (int j = 0; j < st_y; j++)
			stick[i][j] = tmp[st_y - j - 1][i];
}

int cnt_stick()
{
	int ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (nt_book[i][j] == 1)
				ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--)
	{
		cin >> st_x >> st_y;
		init_stick(st_x, st_y);
		for (int i = 0; i < 4; i++)
		{
			if (tt_ntbook1())
				break;
			turn_stick();
		}
	}
	cout << cnt_stick();
}