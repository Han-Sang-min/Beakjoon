#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[503][503];
queue <pair<int, int>> Q;
bool vis[503][503];
int cnt, area;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int x, y;

void board_reset()
{
	bool a;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> a;
			board[i][j] = a;
		}
	}
}
void proc(int i, int j)
{
	int t_area = 1;
	while (!Q.empty())
	{
		pair <int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (vis[nx][ny] || !board[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx > x || ny > y) continue;
			Q.push({ nx, ny });
			vis[nx][ny] = true;
			t_area++;
		}
	}
	if (area < t_area) area = t_area;
}
int main(void) {
	cin >> x >> y;
	board_reset();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (!vis[i][j] && board[i][j])
			{
				Q.push({ i,j });
				vis[i][j] = true;
				proc(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << "\n" << area;
}