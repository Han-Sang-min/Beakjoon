#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		list<char> res = {};
		auto cur = res.begin();
		string s;
		cin >> s;
		for (auto c : s)
		{
			if (c == '<') {
				if (cur != res.begin()) cur--;
			}
			else if (c == '>') {
				if (cur != res.end()) cur++;
			}
			else if (c == '-') {
				if (cur != res.begin()) {
					cur--;
					cur = res.erase(cur);
				}
			}
			else
				res.insert(cur, c);
		}
		for (auto c : res) cout << c;
		cout << "\n";
	}
}