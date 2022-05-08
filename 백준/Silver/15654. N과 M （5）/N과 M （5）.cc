#include <bits/stdc++.h>
using namespace std;

int n, m;
int pnt[10], arr[10];
bool isn_ok[10];

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << pnt[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!isn_ok[i])
        {
            isn_ok[i] = 1;
            pnt[k] = arr[i];
            solve(k + 1);
            isn_ok[i] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    solve(0);
}