// 사장님 달려가고 있습니다

#include <stdio.h>
#include <queue>

using namespace std;

int n;
int arr[101][101];
bool visited[101][101][4][15];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int y, x, d, s;
};

int bfs() {
	queue<Point> q;
	for (int i = 0; i < 4; i++) {
		q.push({ 0, 0, i, 0 });
		visited[0][0][i][0] = true;
	}
	int y, x, ny, nx, d, s, ns, len, t = 0;
	while (!q.empty()) {
		len = q.size();
		while (len--) {
			y = q.front().y;
			x = q.front().x;
			d = q.front().d;
			s = q.front().s;
			q.pop();
			if (y == n - 1 && x == n - 1) return t;

			for (int i = 0; i < 4; i++) {
				if (i == d) ns = s + 1;
				else ns = 1;
				bool flag = false;

				ny = y;
				nx = x;
				for (int ss = 0; ss < ns; ss++) {
					ny += dy[i];
					nx += dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == n) break;
					if (arr[ny][nx]) {
						if (arr[ny][nx] <= t) break;
						if (ss == ns - 1 && arr[ny][nx] <= t + 1) break;
					}
					if (ss == ns - 1) flag = true;
				}
				if (flag && !visited[ny][nx][i][ns]) {
					q.push({ ny, nx, i, ns });
					visited[ny][nx][i][ns] = true;
				}
			}
		}
		t++;
	}
	return -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	int ret = bfs();
	if (ret == -1) printf("Fired\n");
	else printf("%d\n", ret);
	return 0;
}