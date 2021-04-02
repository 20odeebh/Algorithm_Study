// 토마토

#include <stdio.h>
#include <queue>

using namespace std;

int n, m, h, cnt = 0;
int arr[101][101][101];
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0 ,0 ,0 };
struct Point {
	int z, y, x;
};
queue<Point> q;

int bfs() {
	if (!cnt) return 0;
	int z, y, x, nz, ny, nx, len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			z = q.front().z;
			y = q.front().y;
			x = q.front().x;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nz = z + dz[i];
				ny = y + dy[i];
				nx = x + dx[i];
				if (nz < 0 || nz == h || ny < 0 || ny == n || nx < 0 || nx == m) continue;
				if (arr[nz][ny][nx] != 0) continue;
				q.push({ nz, ny, nx });
				arr[nz][ny][nx] = -1;
				cnt--;
			}
			if (!cnt) return t;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &m, &n, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf(" %d", &arr[i][j][k]);
				if (arr[i][j][k] == 1) {
					q.push({ i, j, k });
					arr[i][j][k] = -1;
				}
				else if (arr[i][j][k] == 0) cnt++;
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}