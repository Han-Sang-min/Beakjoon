#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
queue < pair<int, int>> Q;
int board[1003][1003];
int day[1003][1003];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int m, n, res;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				Q.push({ i, j });
				day[i][j] = 1;
			}
			if (board[i][j] == -1) day[i][j] = -1;
		}
	}
	while (!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (day[nx][ny] != 0) continue;
			Q.push({ nx, ny });
			day[nx][ny] = day[cur.X][cur.Y] + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (day[i][j] == 0) {
				cout << -1;
				return 0;
			}
			res = max(res, day[i][j]);
		}
	}
	cout << res - 1;
}