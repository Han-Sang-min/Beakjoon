	#include <bits/stdc++.h>
	using namespace std;

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		int t, n;
		deque<int> deck;
		cin >> t;
		while (t--)	{
			bool err = false, rev = false;
			int num = 0;
			string p, arr;
			cin >> p >> n >> arr;
			for (int i = 1; i + 1 < arr.length(); i++) {
				if (arr[i] == ',') {
					deck.push_back(num);
					num = 0;
				}
				else
					num = 10 * num + (arr[i] - '0');
			}
			if (num != 0) deck.push_back(num);
			for (int i = 0; i < p.length(); i++){
				if (p[i] == 'R') rev = 1 - rev;
				else{
					if (deck.empty()) {
						err = true;
						break;
					}
					if (rev) deck.pop_back();
					else deck.pop_front();
				}
			}
			if (rev) reverse(deck.begin(), deck.end());
			if (err) cout << "error\n";
			else{
				cout << '[';
				for (int i = 0; i < deck.size(); i++) {
					cout << deck[i];
					if(i + 1 != deck.size()) cout << ',';
				}
				cout << "]\n";
			}
			deck.clear();
		}
	}