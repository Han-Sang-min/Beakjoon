#include <bits/stdc++.h>
using namespace std;

void CkPossible(string str1, string str2)
{
	int spl1[26] = {}, spl2[26] = {};
	if (str1.length() != str2.length())
	{
		cout << "Impossible" << "\n";
		return;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		spl1[str1[i] - 'a']++;
		spl2[str2[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		if (spl1[i] != spl2[i]) { cout << "Impossible" << "\n"; return; }
	cout << "Possible" << "\n";
}

int main(void) {
	int n;
	cin >> n;
	string str1, str2;
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2;
		CkPossible(str1, str2);
	}
}