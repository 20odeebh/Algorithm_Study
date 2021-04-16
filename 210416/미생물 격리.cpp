// 미생물 격리

#include <stdio.h>
#include <deque>

using namespace std;

int n, m, k;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
struct Point {
	int sz, d;
};
deque<Point> arr[101][101], tmp[101][101];

int init() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!arr[i][j].empty()) {
				ret += arr[i][j][0].sz;
				arr[i][j].clear();
			}
		}
	}
	return ret;
}

void conquer() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (tmp[y][x].empty()) continue;
			if (tmp[y][x].size() == 1) arr[y][x].push_back(tmp[y][x][0]);
			else {
				int max_sz = 0, sum_sz = 0, d;
				for (auto& it : tmp[y][x]) {
					sum_sz += it.sz;
					if (max_sz < it.sz) {
						max_sz = it.sz;
						d = it.d;
					}
				}
				arr[y][x].push_back({ sum_sz, d });
			}
			tmp[y][x].clear();
		}
	}
}

void move() {
	while (m--) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (arr[y][x].empty()) continue;
				int ny = y + dy[arr[y][x][0].d];
				int nx = x + dx[arr[y][x][0].d];
				if (ny == 0 || ny == n - 1 || nx == 0 || nx == n - 1) {
					if (arr[y][x][0].d % 2) arr[y][x][0].d++;
					else arr[y][x][0].d--;
					arr[y][x][0].sz /= 2;
				}
				if (arr[y][x][0].sz) tmp[ny][nx].push_back(arr[y][x][0]);
				arr[y][x].clear();
			}
		}
		conquer();
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf(" %d %d %d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			int y, x, sz, d;
			scanf(" %d %d %d %d", &y, &x, &sz, &d);
			arr[y][x].push_back({ sz, d });
		}
		move();
		printf("#%d %d\n", tc, init());
	}
	return 0;
}