#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> que;
	for (int i = 1; i <= n; i++)
		que.push(i);
	while (que.size() != 1)
	{
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.back();
}