#include <bits/stdc++.h>
using namespace std;


int main(void) {
	int a, b, c;
	int num_cnt[11] = {};
	cin >> a >> b >> c;
	string str = to_string(a * b * c);
	for (int i = 0; i <= str.length(); i++)
		num_cnt[str[i] - '0']++;
	for (int i = 0; i <= 9; i++)
		cout << num_cnt[i] << '\n';
}