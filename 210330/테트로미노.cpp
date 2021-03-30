// 테트로미노

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, res = 0;
int arr[501][501];
bool visited[501][501];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void not_fuck(int y, int x, int total, int cnt) {
	if (cnt == 3) {
		res = res < total ? total : res;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		not_fuck(ny, nx, total + arr[ny][nx], cnt + 1);
		visited[ny][nx] = false;
	}
}

void make_fuck(int& y, int& x, int& total) {
	for (int k = 0; k < 4; k++) {
		int tmp_total = total;
		int d = 0;
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[(i + k) % 4];
			int nx = x + dx[(i + k) % 4];
			if (ny < 0 || ny == n || nx < 0 || nx == m) break;
			tmp_total += arr[ny][nx];
			d++;
		}
		if (d == 3) res = res < tmp_total ? tmp_total : res;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			not_fuck(i, j, arr[i][j], 0);
			visited[i][j] = false;
			make_fuck(i, j, arr[i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}