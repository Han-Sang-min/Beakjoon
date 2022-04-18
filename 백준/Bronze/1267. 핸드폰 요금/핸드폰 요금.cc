#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, m = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		m += ((x / 60) + 1) * 15;
		y += ((x / 30) + 1) * 10;
	}
	if (m == y) cout << "Y M " << m;
	else if (m < y) cout << "M " << m;
	else cout << "Y " << y;
}