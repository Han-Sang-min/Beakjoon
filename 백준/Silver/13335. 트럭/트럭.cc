#include <bits/stdc++.h>
using namespace std;

int n, w, L, retime, idx, t_cnt;
int trucks[1001];
int brig[101];

void pull_brig()
{
	if (brig[0] != 0) t_cnt++;
	for (int i = 0; i < w - 1; i++)
	{
		brig[i] = brig[i + 1];
		brig[i + 1] = 0;
	}
}

int brig_w()
{
	int ret = 0;
	for (int i = 0; i < w; i++)
		ret += brig[i];
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++)
		cin >> trucks[i];
	while (t_cnt != n)
	{
		pull_brig();
		if (brig_w() + trucks[idx] <= L)
			brig[w - 1] = trucks[idx++];
		retime++;
	}
	cout << retime << "\n";
}