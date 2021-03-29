// 미세먼지 안녕!

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <string.h>

int r, c, t, res = 0;
int arr[51][51], tmp[51][51];
int dy[2][4] = { {0, -1, 0, 1}, {0, 1, 0, -1} };
int dx[2][4] = { {1, 0, -1, 0}, {1, 0, -1, 0} };
std::pair<int, int> p[2];

void spread() {
	memset(tmp, 0, sizeof(tmp));
	tmp[p[0].first][p[0].second] = -1;
	tmp[p[1].first][p[1].second] = -1;

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (arr[y][x] <= 0) continue;
			tmp[y][x] += arr[y][x];
			if (tmp[y][x] < 5) continue;
			int dir = 0;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[0][i];
				int nx = x + dx[0][i];
				if (ny < 0 || ny == r || nx < 0 || nx == c || tmp[ny][nx] == -1) continue;
				tmp[ny][nx] += arr[y][x] / 5;
				dir++;
			}
			tmp[y][x] -= (arr[y][x] / 5) * dir;
		}
	}
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = tmp[i][j];
}

void aircondition() {
	int y, x, cur, next;
	for (int idx = 0; idx < 2; idx++) {
		y = p[idx].first;
		x = p[idx].second + 1;
		cur = arr[y][x];
		arr[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			while (true) {
				y += dy[idx][i];
				x += dx[idx][i];
				if (y < 0 || y == r || x < 0 || x == c || arr[y][x] == -1) {
					y -= dy[idx][i];
					x -= dx[idx][i];
					break;
				}
				next = arr[y][x];
				arr[y][x] = cur;
				cur = next;
			}
		}
	}
}

int main() {
	int idx = 0;
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1) {
				p[idx].first = i;
				p[idx++].second = j;
			}
		}
	}
	while (t--) {
		spread();
		aircondition();
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] > 0)
				res += arr[i][j];
	printf("%d\n", res);
	return 0;
}