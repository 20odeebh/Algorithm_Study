// 양파깡 만들기

#include <stdio.h>
#include <limits.h>

int n, m;
int arr[31][31];
bool visited[31][31];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
struct Point {
	int ret, sy, sx, fy, fx;
}p[31];

int cut(int sy, int sx, int fy, int fx, bool flag) {
	if (visited[sy][sx] || visited[fy][fx]) return -INT_MAX;

	int ret = 0;
	int move_cnt[4] = { fx - sx, fy - sy, fx - sx, fy - sy };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < move_cnt[i]; j++) {
			sy += dy[i];
			sx += dx[i];
			if (visited[sy][sx]) return -INT_MAX;
			if (flag) ret += arr[sy][sx];
			else visited[sy][sx] = true;
		}
	}
	return ret;
}

bool find(int idx) {
	int ret = -INT_MAX;
	for (int sy = 0; sy < n - 2; sy++) {
		for (int sx = 0; sx < n - 2; sx++) {
			for (int fy = sy + 2; fy < n; fy++) {
				for (int fx = sx + 2; fx < n; fx++) {
					int val = cut(sy, sx, fy, fx, true);
					if (ret < val) {
						ret = val;
						p[idx] = { ret, sy, sx, fy, fx };
					}
				}
			}
		}
	}
	if (ret == -INT_MAX) return false;
	cut(p[idx].sy, p[idx].sx, p[idx].fy, p[idx].fx, false);
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	for(int i = 0; i < m; i++) {
		if (!find(i)) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < m; i++)
		printf("%d %d %d %d %d\n", p[i].ret, p[i].sy + 1, p[i].sx + 1, p[i].fy + 1, p[i].fx + 1);
	return 0;
}