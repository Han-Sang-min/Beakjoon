#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
queue<int> Q;
int sec[100002];
int n, k;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	Q.push(n);
	sec[n] = 1;
	while (sec[k] == 0)
	{
		int cur = Q.front(); Q.pop();
		for (int np : {cur - 1, cur + 1, cur * 2})
		{
			if (np < 0 || np > 100000 || sec[np] != 0) continue;
			Q.push(np);
			sec[np] = sec[cur] + 1;
		}
	}
	cout << sec[k] - 1;
}