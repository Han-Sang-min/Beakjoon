#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string cmd;
	queue<int> que;
	cin >> n;
	while (n--)
	{
		cin >> cmd;
		if (cmd == "push") {
			int a;
			cin >> a;
			que.push(a);
		}
		else if (cmd == "pop") {
			if (que.empty()) cout << -1 << "\n";
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (cmd == "size") {
			cout << que.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << que.empty() << "\n";
		}
		else if (cmd == "front") {
			if (que.empty()) cout << -1 << "\n";
			else cout << que.front() << "\n";
		}
		else if (cmd == "back") {
			if (que.empty()) cout << -1 << "\n";
			else cout << que.back() << "\n";
		}
	}
}