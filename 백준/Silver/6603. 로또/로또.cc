#include <bits/stdc++.h>
using namespace std;

int n, ck_nu;
int arr[13], pnt[6];
bool isn_ok[13];
void solve(int k)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << pnt[i] << ' ';
        cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        if (!isn_ok[i] && ck_nu < arr[i])
        {
            isn_ok[i] = 1;
            ck_nu = arr[i];
            pnt[k] = arr[i];
            solve(k + 1);
            ck_nu = 0;
            isn_ok[i] = 0;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(0);
        cout << '\n';
    }
}