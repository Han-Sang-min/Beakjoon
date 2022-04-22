#include <bits/stdc++.h>
using namespace std;

int arr[201];
int v_arr[101];

int main(void) {
	int N, ck_nu;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v_arr[i];
	for (int i = 0; i < N; i++) arr[v_arr[i] + 100]++;
	cin >> ck_nu;
	cout << arr[ck_nu + 100];
}