#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3][4] = {0};
	int sum[3] = {0};
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		sum[i] = a[i][0] + a[i][1] + a[i][2] + a[i][3];
	}
	for (int i = 0; i < 3; i++)
		cout << "DCBAE"[sum[i]] << "\n";
}