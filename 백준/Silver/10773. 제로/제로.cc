#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, res = 0;
	cin >> n;
	stack<int> stk;
	while (n--)
	{
		cin >> a;
		if (a == 0) stk.pop();
		else stk.push(a);
	}
	while (!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	cout << res;
}