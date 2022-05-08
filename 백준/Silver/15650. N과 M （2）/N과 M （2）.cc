#include <bits/stdc++.h>
using namespace std;

int n, m, ck_nu;
int arr[8];
void solve(int k)
{
    if (m == k)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ck_nu < i)
        {
            ck_nu = i; arr[k] = i;
            solve(k + 1);
            ck_nu = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve(0);
}