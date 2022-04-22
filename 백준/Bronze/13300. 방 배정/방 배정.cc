#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int std[2][6] = {};
	int n, k, sex, grad, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> sex >> grad;
		std[sex][grad - 1]++;
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 6; j++)
		{
			if (std[i][j] % k != 0) res += (std[i][j] / k) + 1;
			else res += std[i][j] / k;
		}
	cout << res;
}