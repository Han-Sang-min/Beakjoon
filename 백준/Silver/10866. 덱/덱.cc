#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string cmd;
	deque<int> deck;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			int a;
			cin >> a;
			deck.push_front(a);
		}
		else if (cmd == "push_back") {
			int a;
			cin >> a;
			deck.push_back(a);
		}
		else if (cmd == "pop_front") {
			if (deck.empty()) cout << -1 << "\n";
			else {
				cout << deck.front() << "\n";
				deck.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (deck.empty()) cout << -1 << "\n";
			else {
				cout << deck.back() << "\n";
				deck.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << deck.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << deck.empty() << "\n";
		}
		else if (cmd == "front") {
			if (deck.empty()) cout << -1 << "\n";
			else cout << deck.front() << "\n";
		}
		else if (cmd == "back") {
			if (deck.empty()) cout << -1 << "\n";
			else cout << deck.back() << "\n";
		}
	}
}