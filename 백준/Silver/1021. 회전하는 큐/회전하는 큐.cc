#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt = 0;
	cin >> n >> m;
	deque<int> deck;
	for (int i = 1; i <= n; i++) deck.push_back(i);
	while (m--){
		int a;
		cin >> a;
		int idx = find(deck.begin(), deck.end(), a) - deck.begin();
		while (deck.front() != a){
			if (idx < deck.size() - idx) {
				deck.push_back(deck.front());
				deck.pop_front();
				cnt++;
			}
			else {
				deck.push_front(deck.back());
				deck.pop_back();
				cnt++;
			}
		}
		deck.pop_front();
	}
	cout << cnt;
}