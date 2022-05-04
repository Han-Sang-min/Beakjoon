	#include <bits/stdc++.h>
	using namespace std;

	int n;
	int cnt[2];
	int pap[150][150];

	bool is_ok(int a, int b, int n)
	{
		for (int i = a; i < n + a; i++)
			for (int j = b; j < n + b; j++)
				if (pap[a][b] != pap[i][j]) return false;
		return true;
	}
	void proc(int a, int b, int n)
	{
		if (is_ok(a, b, n))
		{
			cnt[pap[a][b]]++;
			return;
		}
		int half = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				proc(a + i * half, b + j * half, half);
	}
	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
	
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> pap[i][j];
		proc(0, 0, n);
		cout << cnt[0] << "\n" << cnt[1] << "\n";
	}