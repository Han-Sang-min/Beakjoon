#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> V, ans;
	for (int i = 1; i <= n; i++)
		V.push_back(i);

	for (int i = 0; ans.size() < n; i++) {
		if (i % k == k - 1) ans.push_back(V[i]);
		else V.push_back(V[i]);
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << ans[i]; 
		else cout << ans[i] << ", ";
	}
	cout << ">";
}