	#include <bits/stdc++.h>
	using namespace std;

	int n;
	int cnt[3];
	int pap[2200][2200];

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
			cnt[pap[a][b] + 1]++;
			return;
		}
		int tn = n / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				proc(a + i * tn, b + j * tn, tn);
	}
	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
	
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> pap[i][j];
		proc(0, 0, n);
		for (int i = 0; i < 3; i++)
			cout << cnt[i] << "\n";
	}