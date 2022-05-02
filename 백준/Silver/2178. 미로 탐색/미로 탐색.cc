#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
char board[103][103];
int dist[103][103];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	Q.push({ 0, 0 });
	dist[0][0] = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] != '1' || dist[nx][ny]) continue;
			Q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
		}
	}
	cout << dist[n-1][m-1];
}