#include <bits/stdc++.h>
using namespace std;

int mth_num[2000002];
int len, fi_num, cnt = 0;
int num[1000001];

int main(void) {
	cin >> len;
	for (int i = 0; i < len; i++) cin >> num[i];
	cin >> fi_num;
	for (int i = 0; i < len; i++)
	{
		if (fi_num - num[i] < 0) continue;
		else if (mth_num[fi_num - num[i]]) cnt++;
		else mth_num[num[i]] = 1;
	}
	cout << cnt;
}