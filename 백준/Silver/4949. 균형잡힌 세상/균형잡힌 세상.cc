	#include <bits/stdc++.h>
	using namespace std;

	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		while (true)
		{
			string arr;
			bool is_err = 0;
			stack<char> brac;
			getline(cin, arr);
			if (arr == ".") break;
			for (auto c : arr)
			{
				if (c == '[' || c == '(') brac.push(c);
				else if (c == ']') {
					if (brac.empty() || brac.top() != '[') {
						is_err = 1;
						break;
					}
					brac.pop();
				}
				else if (c == ')') {
					if (brac.empty() || brac.top() != '(') {
						is_err = 1;
						break;
					}
					brac.pop();
				}
			}
			if (!brac.empty()) is_err = 1;
			if (is_err) cout << "no\n";
			else cout << "yes\n";
		}
	}