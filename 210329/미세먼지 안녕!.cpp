#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int r, c, t,vy,vx;
int a[50][50],map[50][50], dy[] = {0,-1,0,1}, dx[] = {1,0,-1,0};

void spread() {
	memset(a, 0, sizeof(a));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ni = i + dy[k];
					int nj = j + dx[k];
					if (ni < 0 || ni >= r || nj < 0 || nj >= c || map[ni][nj] == -1)continue;
					a[ni][nj] += map[i][j]/5;
					cnt++;
				}
				map[i][j] -= (map[i][j] / 5) * cnt;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += a[i][j];
		}
	}
}

void go_up() {
	vector<pair<int, int>>v;

	int sy = vy;
	int sx = vx+1;
	int d = 0;
	
	while (true) {
		//cout << sy << " " << sx << "\n";
		if (sy+1 ==vy && sx ==vx )break;
		v.push_back({ sy,sx });
		int ny = sy + dy[d];
		int nx = sx + dx[d];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
			d = (d + 1) % 4;
			ny = sy + dy[d];
			nx = sx + dx[d];
		}
		sy = ny;
		sx = nx;
	}

	sy = vy-1;
	sx = vx;
	d = 1;
	for (int i = v.size() - 1; i >= 0; i--) {
		map[sy][sx] = map[v[i].first][v[i].second];
		int ny = sy + dy[d];
		int nx = sx + dx[d];
		if (ny < 0 || ny > vy || nx < 0 || nx >= c) {
			d = (d + 3) % 4;
			ny = sy + dy[d];
			nx = sx + dx[d];
		}
		sy = ny;
		sx = nx;
	}
	map[vy][vx + 1] = 0;
}

void go_down() {
	vector<pair<int, int>>v;

	int sy = vy+1;
	int sx = vx + 1;
	int d = 0;

	while (true) {
		if (sy - 1 == vy+1 && sx == vx)break;
		v.push_back({ sy,sx });
		int ny = sy + dy[d];
		int nx = sx + dx[d];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
			d = (d + 3) % 4;
			ny = sy + dy[d];
			nx = sx + dx[d];
		}
		sy = ny;
		sx = nx;
	}

	sy = vy +2;
	sx = vx;
	d = 3;
	for (int i = v.size() - 1; i >= 0; i--) {
		map[sy][sx] = map[v[i].first][v[i].second];
		int ny = sy + dy[d];
		int nx = sx + dx[d];
		if (ny < vy+1 || ny >= r || nx < 0 || nx >= c) {
			d = (d + 1) % 4;
			ny = sy + dy[d];
			nx = sx + dx[d];
		}
		sy = ny;
		sx = nx;
	}
	map[vy+1][vx + 1] = 0;
}

int main() {
	cin >> r >> c >> t;

	bool flag = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (!flag && map[i][j] == -1) {
				flag = true;
				vy = i;
				vx = j;
			}
		}
	}
	while (t--) {
		spread();
		go_up();
		go_down();
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans;
}
