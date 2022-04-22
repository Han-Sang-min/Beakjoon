#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int spl1[26] = {}, spl2[26] = {}, res = 0;
	char arr1[1001] = {}, arr2[1001] = {};
	cin >> arr1 >> arr2;
	int len = strlen(arr1) > strlen(arr2) ? strlen(arr1) : strlen(arr2);
	for (int i = 0; i < len; i++)
	{
		if (arr1[i])
			spl1[arr1[i] - 'a']++;
		if (arr2[i])
			spl2[arr2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
		res += abs(spl1[i] - spl2[i]);
	cout << res;
}