// 화살표 미로 (Normal)

#include <stdio.h>
#include <queue>

using namespace std;

int r, c, k;
char arr[51][51];
bool visited[51][51][151][151];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Point {
	int y, x, L, R;
};

int get_direction(int y, int x) {
	if (arr[y][x] == 'U') return 3;
	else if (arr[y][x] == 'D') return 1;
	else if (arr[y][x] == 'L') return 2;
	else return 0;
}

int bfs() {
	queue<Point> q;
	q.push({ 0, 0, k, k });
	visited[0][0][k][k] = true;
	int y, x, d, ny, nx, nd, L, R, nL, nR;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		L = q.front().L;
		R = q.front().R;
		q.pop();
		if (y == r - 1 && x == c - 1) return true;
		d = get_direction(y, x);

		ny = y + dy[d];
		nx = x + dx[d];
		if (!(ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][R])) {
			q.push({ ny, nx, L, R });
			visited[ny][nx][L][R] = true;
		}

		if (L) {
			nL = L;
			nd = d;
			for (int i = 0; i < 3; i++) {
				if (nL-- == 0) break;
				nd = (nd + 3) % 4;
				ny = y + dy[nd];
				nx = x + dx[nd];
				if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][nL][R]) continue;
				q.push({ ny, nx, nL, R });
				visited[ny][nx][nL][R] = true;
			}
		}

		if (R) {
			nR = R;
			nd = d;
			for (int i = 0; i < 3; i++) {
				if (nR-- == 0) break;
				nd = (nd + 1) % 4;
				ny = y + dy[nd];
				nx = x + dx[nd];
				if (ny < 0 || ny == r || nx < 0 || nx == c || visited[ny][nx][L][nR]) continue;
				q.push({ ny, nx, L, nR });
				visited[ny][nx][L][nR] = true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < r; i++) scanf("%s", arr[i]);
	int ret = bfs();
	if (ret) printf("Yes\n");
	else printf("No\n");
	return 0;
}