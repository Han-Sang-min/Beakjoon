#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<int> stk;
	string cmd;
	cin >> n;
	while (n--)
	{
		cin >> cmd;
		if (cmd == "push"){
			int a;
			cin >> a;
			stk.push(a);
		}
		else if (cmd == "pop"){
			if (stk.empty()) cout << -1 << "\n";
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (cmd == "size") {
			cout << stk.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << (int)stk.empty() << "\n";
		}
		else if (cmd == "top") {
			if (stk.empty()) cout << -1 << "\n";
			else cout << stk.top() << "\n";
		}
	}
}