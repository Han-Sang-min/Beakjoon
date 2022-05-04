	#include <bits/stdc++.h>
	using namespace std;

	int n;
	char img[70][70];
	bool is_ok(int a, int b, int n)
	{
		for (int i = a; i < n + a; i++)
			for (int j = b; j < n + b; j++)
				if (img[a][b] != img[i][j]) return false;
		return true;
	}
	void proc(int a, int b, int n)
	{
		if(is_ok(a, b, n))
		{
			cout << img[a][b];
			return;
		}
		cout << '(';
		int half = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				proc(a + i * half, b + j * half, half);
		cout << ')';
	}
	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
	
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> img[i][j];
		proc(0, 0, n);
	}