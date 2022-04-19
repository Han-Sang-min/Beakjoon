#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string arr;
	int num = 0;
	cin >> arr;
	for (char j = 'a'; j <= 'z'; j++)
	{
		num = 0;
		for (int i = 0; i < arr.length(); i++)
			if (arr[i] == j) num++;
		cout << num << ' ';
	}
}