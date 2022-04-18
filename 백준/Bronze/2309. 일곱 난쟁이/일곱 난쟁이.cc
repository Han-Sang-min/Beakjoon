#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[9] = { 0 };
	int sum = 0;
	int a, b;
	
	for (int i = 0; i < 9; i++) { cin >> arr[i]; sum += arr[i]; }
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++) if (sum - 100 == arr[i] + arr[j]) { a = i; b = j; break; }
	for (int k = 0; k < 9; k++) if(k != a && k != b) cout << arr[k] << '\n';
}