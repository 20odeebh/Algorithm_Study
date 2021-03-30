// 섬의 개수

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int w, h, cnt;
bool arr[51][51], visited[51][51];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	int ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w || visited[ny][nx] || !arr[ny][nx]) continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
		}
	}
}

int main() {
	while (true) {
		scanf(" %d %d", &w, &h);
		if (!w && !h) break;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf(" %d", &arr[i][j]);
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}