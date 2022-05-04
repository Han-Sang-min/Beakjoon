	#include <bits/stdc++.h>
	using namespace std;

	int n;
	void proc(int i, int j, int n)
	{

		int tn = n / 3;
		if (i / tn % 3 == 1 && j / tn % 3 == 1) cout << " ";
		else if (tn != 1) proc(i, j, n / 3);
		else cout << "*";
	}
	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
	
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				proc(i, j, n);
			cout << "\n";
		}
	}