#include <bits/stdc++.h>
using namespace std;

int n, m;
int star_map[8][8];
int cctv_info[8][3];
int tmp;
int cnt_cctv;
int cnt_wall;
int least_size = 100;

int count_blind_spot()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (star_map[i][j] == 0)
				ret++;
	return ret;
}

void fill_map0(int val, int cctv_pos1, int cctv_pos2, int k)
{
	for (int i = cctv_pos1; i >= 0; i--)
	{
		if (star_map[i][cctv_pos2] == 6)
			break;
		else if (star_map[i][cctv_pos2] > 0)
			continue;
		else if (star_map[i][cctv_pos2] < 0 && star_map[i][cctv_pos2] > -1 - k)
			continue;
		else
			star_map[i][cctv_pos2] = val;
	}
}

void fill_map1(int val, int cctv_pos1, int cctv_pos2, int k)
{
	for (int i = cctv_pos1; i < m; i++)
	{
		if (star_map[cctv_pos2][i] == 6)
			break;
		else if (star_map[cctv_pos2][i] > 0)
			continue;
		else if (star_map[cctv_pos2][i] < 0 && star_map[cctv_pos2][i] > -1 - k)
			continue;
		else
			star_map[cctv_pos2][i] = val;
	}
}

void fill_map2(int val, int cctv_pos1, int cctv_pos2, int k)
{
	for (int i = cctv_pos1; i < n; i++)
	{
		if (star_map[i][cctv_pos2] == 6)
			break;
		else if (star_map[i][cctv_pos2] > 0)
			continue;
		else if (star_map[i][cctv_pos2] < 0 && star_map[i][cctv_pos2] > -1 - k)
			continue;
		else
			star_map[i][cctv_pos2] = val;
	}
}

void fill_map3(int val, int cctv_pos1, int cctv_pos2, int k)
{
	for (int i = cctv_pos1; i >= 0; i--)
	{
		if (star_map[cctv_pos2][i] == 6)
			break;
		else if (star_map[cctv_pos2][i] > 0)
			continue;
		else if (star_map[cctv_pos2][i] < 0 && star_map[cctv_pos2][i] > -1 - k)
			continue;
		else
			star_map[cctv_pos2][i] = val;
	}
}

void pnt_least_blind_spot(int k){
	if (k == cnt_cctv) {
		tmp = count_blind_spot();
		if (tmp < least_size)
			least_size = tmp;
		return;
	}
	for (int i = 0; i < 4; i++) {
		switch (cctv_info[k][0]){
			case 1:
				switch (i){
					case 0:
						fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
						pnt_least_blind_spot(k + 1);
						fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
						break;
					case 1:
						fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
						pnt_least_blind_spot(k + 1);
						fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
						break;
					case 2:
						fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
						pnt_least_blind_spot(k + 1);
						fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
						break;
					case 3:
						fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
						pnt_least_blind_spot(k + 1);
						fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
						break;
				}
				break;
			case 2:
				switch (i) {
				case 0:
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					pnt_least_blind_spot(k + 1);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					i++;
					break;
				case 3:
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					i++;
					break;
				}
				break;
			case 3:
				switch (i) {
				case 0:
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					break;
				case 1:
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					pnt_least_blind_spot(k + 1);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					break;
				case 2:
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					break;
				case 3:
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					pnt_least_blind_spot(k + 1);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					break;
				}
				break;
			case 4:
				switch (i) {
				case 0:
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					pnt_least_blind_spot(k + 1);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					break;
				case 1:
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					break;
				case 2:
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					pnt_least_blind_spot(k + 1);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					break;
				case 3:
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					break;
				}
				break;
			case 5:
				switch (i) {
				case 0:
					fill_map0(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(-1 - k, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(-1 - k, cctv_info[k][2], cctv_info[k][1], k);
					pnt_least_blind_spot(k + 1);
					fill_map0(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map1(0, cctv_info[k][2], cctv_info[k][1], k);
					fill_map2(0, cctv_info[k][1], cctv_info[k][2], k);
					fill_map3(0, cctv_info[k][2], cctv_info[k][1], k);
					i += 3;
					break;
				}
				break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> star_map[i][j];
			if (star_map[i][j] == 6)
				cnt_wall++;
			else if (star_map[i][j] > 0){
				cctv_info[cnt_cctv][0] = star_map[i][j];
				cctv_info[cnt_cctv][1] = i;
				cctv_info[cnt_cctv][2] = j;
				cnt_cctv++;
			}
		}
	}
	pnt_least_blind_spot(0);
	cout << least_size;
}