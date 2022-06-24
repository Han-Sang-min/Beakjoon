#include <bits/stdc++.h>
using namespace std;

int n, m;
int least = 2147483647;
int city[52][52];
int check[20];
vector <pair<int, int>> house_loc;
vector <pair<int, int>> chicken_loc;

void chicken_dist()
{
	int tmp2 = 0;
	for (int i = 0; i < house_loc.size(); i++)
	{
		int tmp1 = 0xffffff;
		for (int j = 0; j < chicken_loc.size(); j++)
		{
			if (check[j] == 0) continue;
			tmp1 = min(tmp1, abs(chicken_loc[j].first - house_loc[i].first) + abs(chicken_loc[j].second - house_loc[i].second));
		}
		tmp2 += tmp1;
	}
	least = min(least, tmp2);
}

void next_case(int k, int nu)
{
	if (k == m)
	{
		chicken_dist();
		return;
	}
	for (int i = nu; i < chicken_loc.size(); i++)
	{
		check[i] = 1;
		next_case(k + 1, i + 1);
		check[i] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				house_loc.push_back({ i, j });
			else if (city[i][j] == 2)
				chicken_loc.push_back({ i, j });
		}
	}
	next_case(0, 0);
	cout << least << "\n";
}