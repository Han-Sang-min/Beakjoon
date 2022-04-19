#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int num[10] = {};
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		num[str[i] - '0']++;
	num[6] += num[9];
	if (num[6] % 2) ++num[6] /= 2;
	else num[6] /= 2;
	cout << *max_element(num, num + 9);
}