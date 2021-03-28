#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int a[8][8], cctvNum = 0;
pair<int, int> cctv[8];
int ans = 64;
void fill(int x, int y, int type, int dir) {
	int x2 = x + dx[dir], y2 = y + dy[dir];
	//1번
	while (x2 >= 0 && x2 < n) {
		if (dx[dir] == 0)break;
		if (a[x2][y] == 0)a[x2][y] = 7;
		else {
			if (a[x2][y] == 6)break;
		}
		x2 += dx[dir];
	}
	while (y2 >= 0 && y2 < m) {
		if (dy[dir] == 0)break;
		if (a[x][y2] == 0)a[x][y2] = 7;
		else {
			if (a[x][y2] == 6)break;
		}
		y2 += dy[dir];
	}
	//2번,4번
	if (type == 2 || type == 4) {
		x2 = x - dx[dir], y2 = y - dy[dir];
		while (x2 >= 0 && x2 < n) {
			if (dx[dir] == 0)break;
			if (a[x2][y] == 0)a[x2][y] = 7;
			else {
				if (a[x2][y] == 6)break;
			}
			x2 -= dx[dir];
		}
		while (y2 >= 0 && y2 < m) {
			if (dy[dir] == 0)break;
			if (a[x][y2] == 0)a[x][y2] = 7;
			else {
				if (a[x][y2] == 6)break;
			}
			y2 -= dy[dir];
		}
	}
	//3번, 4번
	if (type == 3 || type == 4) {
		x2 = x + dx[(dir + 1) % 4], y2 = y + dy[(dir + 1) % 4];
		while (x2 >= 0 && x2 < n) {
			if (dx[(dir + 1) % 4] == 0)break;
			if (a[x2][y] == 0)a[x2][y] = 7;
			else {
				if (a[x2][y] == 6)break;
			}
			x2 += dx[(dir + 1) % 4];
		}
		while (y2 >= 0 && y2 < m) {
			if (dy[(dir + 1) % 4] == 0)break;
			if (a[x][y2] == 0)a[x][y2] = 7;
			else {
				if (a[x][y2] == 6)break;
			}
			y2 += dy[(dir + 1) % 4];
		}
	}

}
void go(int idx) {
	if (idx == cctvNum) {
		int tcnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0)tcnt++;
			}
		}
		ans = min(ans, tcnt);
		return;
	}
	int originRow[8], originCol[8];
	for (int i = 0; i < n; i++) {
		originRow[i] = a[i][cctv[idx].second];
	}
	for (int i = 0; i < m; i++) {
		originCol[i] = a[cctv[idx].first][i];
	}
	for (int i = 0; i < 4; i++) {
		fill(cctv[idx].first, cctv[idx].second, a[cctv[idx].first][cctv[idx].second], i);
		go(idx + 1);
		for (int j = 0; j < n; j++) {
			a[j][cctv[idx].second] = originRow[j];
		}
		for (int j = 0; j < m; j++) {
			a[cctv[idx].first][j] = originCol[j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 4) {
				cctv[cctvNum].first = i;
				cctv[cctvNum++].second = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 5) {
				for (int k = 0; k < 4; k++) {
					int x2 = i + dx[k], y2 = j + dy[k];
					while (x2 >= 0 && x2 < n) {
						if (dx[k] == 0)break;
						if (a[x2][y2] == 0)a[x2][y2] = 9;
						else {
							if (a[x2][y2] == 6)break;
						}
						x2 += dx[k];
					}
					while (y2 >= 0 && y2 < m) {
						if (dy[k] == 0)break;
						if (a[x2][y2] == 0)a[x2][y2] = 9;
						else {
							if (a[x2][y2] == 6)break;
						}
						y2 += dy[k];
					}
				}
			}
		}
	}
	go(0);
	cout << ans << '\n';
}