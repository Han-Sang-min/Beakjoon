#include <bits/stdc++.h>
using namespace std;

int proc(int n)
{
    if (n == 1) return n;
    return n + proc(n - 1);
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << proc(n) << "\n";
 }