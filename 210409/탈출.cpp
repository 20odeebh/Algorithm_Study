// 탈출

#include <stdio.h>
#include <queue>

using namespace std;

int r, c;
char arr[51][51];
bool visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> D, water;

int bfs() {
	int y, x, ny, nx, len, t = 0;
	while (!D.empty()) {
		t++;
		len = water.size();
		while (len--) {
			y = water.front().first;
			x = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c) continue;
				if (arr[ny][nx] == '.') {
					water.push(make_pair(ny, nx));
					arr[ny][nx] = '*';
				}
			}
		}
		len = D.size();
		while (len--) {
			y = D.front().first;
			x = D.front().second;
			D.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx]) continue;
				if (arr[ny][nx] == 'D') return t;
				if (arr[ny][nx] == '.') {
					D.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'S') {
				D.push(make_pair(i, j));
				visited[i][j] = true;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == '*') water.push(make_pair(i, j));
		}
	}
	int res = bfs();
	if (res == -1) printf("KAKTUS\n");
	else printf("%d\n", res);
	return 0;
}