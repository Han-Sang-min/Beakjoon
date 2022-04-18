#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + i; j++)
		{
			if (n - i - 1 <= j && n + i - 1 >= j) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j + i < (n - 1) * 2 + 1; j++)
		{
			if (i <= j && (n - 1) * 2 >= j + i) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
}