#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0, temp = 100, x;
	for (int i = 0; i < 7; i++)
	{
		cin >> x;
		if (x % 2 == 1) 
		{
			sum += x;
			if (temp > x) temp = x;
		}
	}
	if (sum == 0 && temp == 100) cout << "-1";
	else cout << sum << '\n' << temp;
}