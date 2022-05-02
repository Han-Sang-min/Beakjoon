#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
queue<pair<int, int>> J;
queue<pair<int, int>> F;
char board[1003][1003];
int jh[1003][1003];
int fire[1003][1003];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J'){
				J.push({ i, j });
				jh[i][j] = 1;
			}
			if (board[i][j] == 'F') {
				F.push({ i, j });
				fire[i][j] = 1;
			}
		}
	}
	while (!F.empty())
	{
		pair<int, int> cur = F.front(); F.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (board[nx][ny] == '#' || fire[nx][ny] > 0) continue;
			F.push({ nx, ny });
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
		}
	}
	while (!J.empty())
	{
		pair<int, int> cur = J.front(); J.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << jh[cur.X][cur.Y];
				return 0;
			}
			if (board[nx][ny] == '#' || jh[nx][ny] > 0) continue;
			if (fire[nx][ny] != 0 && fire[nx][ny] <= jh[cur.X][cur.Y] + 1) continue;
			J.push({ nx, ny });
			jh[nx][ny] = jh[cur.X][cur.Y] + 1;
		}
	}
	cout << "IMPOSSIBLE";
}