#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) {
	dat[tail++] = x;
}

void back() {
	cout << dat[tail - 1] << "\n";
}

void front() {
	cout << dat[head] << "\n";
}

void pop() {
	front();
	head++;
}

int main(void) {
	int n;
	string cmd;
	cin >> n;
	while (n--)
	{
		cin >> cmd;
		if (cmd == "push") {
			int a;
			cin >> a;
			push(a);
		}
		else if (cmd == "pop") {
			if (head == tail) cout << -1 << "\n";
			else pop();
		}
		else if (cmd == "size") {
			cout << tail - head << "\n";
		}
		else if (cmd == "empty") {
			if (head == tail) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd == "front") {
			if (head == tail) cout << -1 << "\n";
			else front();
		}
		else if (cmd == "back") {
			if (head == tail) cout << -1 << "\n";
			else back();
		}
	}
}