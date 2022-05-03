#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll pow(ll a, ll b, ll c)
{
	if (b == 1) return a % c;
	ll rem = pow(a, b / 2, c);
	if (b % 2) return rem * rem % c * a % c;
	return rem * rem % c;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	cout << pow(a, b, c);
}