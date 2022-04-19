#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n*2 - 1 - i; j++)
		{
			if (i <= j && n*2 -2 - i >= j) cout << "*";
			else cout << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n + 1 + i; j++)
		{
			if (n - 1 - i <= j && n + i - 1 >= j) cout << "*";
			else if (j == n * 2 - 1) cout << "";
			else cout << " ";
		}
		cout << '\n';
	}
}