// 어른상어

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int arr[21][21][2] = { { {0, }, }, };
int tmp[21][21][2];
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int shark[401][5][4];

class Point {
public:
	int y, x, sz, d;
};
Point p[401];

int move() {
	queue<Point> q;
	for (int i = 1; i <= m; i++)
		q.push(p[i]);
	int y, x, ny, nx, sz, d, len, cnt = 1;
	bool flag;
	while (true) {
		if (cnt > 1001) return -1;
		len = q.size();
		if (len == 1) return cnt - 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < 2; k++)
					tmp[i][j][k] = arr[i][j][k];
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			sz = q.front().sz;
			d = q.front().d;
			flag = true;
			q.pop();

			for (int i = 0; i < 4; i++) {
				ny = y + dy[shark[sz][d][i]];
				nx = x + dx[shark[sz][d][i]];
				if (ny < 0 || ny == n || nx < 0 || nx == n) continue;
				if (arr[ny][nx][0] == 0 || arr[ny][nx][0] < cnt || arr[ny][nx][0] - k == cnt) {
					y = ny;
					x = nx;
					d = shark[sz][d][i];
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < 4; j++) {
					ny = y + dy[shark[sz][d][j]];
					nx = x + dx[shark[sz][d][j]];
					if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx][1] != sz) continue;
					y = ny;
					x = nx;
					d = shark[sz][d][j];
					break;
				}
			}
			if (tmp[y][x][0] - k == cnt) continue;
			tmp[y][x][0] = k + cnt;
			tmp[y][x][1] = sz;
			q.push({ y, x, sz, d });
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < 2; k++)
					arr[i][j][k] = tmp[i][j][k];
		cnt++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int sz, d;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j][0];
			if (arr[i][j][0] != 0) {
				p[arr[i][j][0]] = { i, j, arr[i][j][0] };
				arr[i][j][1] = arr[i][j][0];
				arr[i][j][0] = k;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> d;
		p[i].d = d;
	}
	 
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= 4; j++) 
			for (int k = 0; k < 4; k++) 
				cin >> shark[i][j][k];
	cout << move() << '\n';
	return 0;
}