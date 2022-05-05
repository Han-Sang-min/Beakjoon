#include <bits/stdc++.h>
using namespace std;

char board[3074][6148];
int n;

void solve(int x, int y, int n) {
    if (n == 3)
    {
        board[x][y] = '*';
        board[x + 1][y + 1] = '*';
        board[x + 1][y - 1] = '*';
        for (int i = -2; i < 3; i++) board[x + 2][y + i] = '*';
        return;
    }
    int tn = n / 2;
    solve(x, y, tn);
    solve(x + tn, y + tn, tn);
    solve(x + tn, y - tn, tn);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(&board[0][0], &board[3073][6147], ' ');
    solve(0, n - 1, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2 - 1; j++)
            cout << board[i][j];
        cout << "\n";
    }
}