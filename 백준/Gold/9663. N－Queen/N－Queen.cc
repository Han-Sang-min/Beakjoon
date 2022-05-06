#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool is_ok1[30];
bool is_ok2[30];
bool is_ok3[30];
void solve(int k)
{
    if (k == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!is_ok1[i] && !is_ok2[i + k] && !is_ok3[k - i + n])
        {
            is_ok1[i] = true; is_ok2[i + k] = true; is_ok3[k - i + n] = true;
            solve(k + 1);
            is_ok1[i] = false; is_ok2[i + k] = false; is_ok3[k - i + n] = false;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(0);
    cout << cnt;
}