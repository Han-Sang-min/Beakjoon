#include <bits/stdc++.h>
using namespace std;

int n, m;
int pnt[10], arr[10];
bool ck_nu[10];

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << pnt[i] << ' ';
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!ck_nu[i] && tmp != arr[i])
        {
            ck_nu[i] = true;
            tmp = arr[i];
            pnt[k] = arr[i];
            solve(k + 1);
            ck_nu[i] = false;
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