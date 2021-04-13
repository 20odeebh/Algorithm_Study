// 전투 시뮬레이션

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n, h, w, m, k;
int arr[501][501], map[501][501];
int visited[501][501];
int height[10];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

struct Point {
	int m, t, y, x;
};
vector<Point> v;

bool is_movable(int& y, int& x, int& t) {
	int ny, nx;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
		if (map[ny][nx] && t != v[map[ny][nx]].t) return false;;
	}
	return true;
}

bool move(int& idx, int& a, int& b) {
	if (height[arr[a][b]] == -1 || map[a][b]) return false;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(v[idx].m, make_pair(v[idx].y, v[idx].x)));
	memset(visited, 0, sizeof(visited));
	visited[v[idx].y][v[idx].x] = v[idx].m;

	int y, x, ny, nx, s, t = v[idx].t;
	while (!pq.empty()) {
		y = pq.top().second.first;
		x = pq.top().second.second;
		s = pq.top().first;
		pq.pop();
		if (visited[y][x] > s) continue;
		if (abs(y - a) + abs(x - b) > 20) continue;

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w || height[arr[ny][nx]] == -1) continue;
			if (s - height[arr[ny][nx]] < 0) continue;
			if (map[ny][nx] && t != v[map[ny][nx]].t) continue;
			if (ny == a && nx == b) return true;
			if (!is_movable(ny, nx, t)) continue;
			if (s - height[arr[ny][nx]] <= visited[ny][nx]) continue;
			pq.push(make_pair(s - height[arr[ny][nx]], make_pair(ny, nx)));
			visited[ny][nx] = s - height[arr[ny][nx]];
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &n, &h, &w);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 1; i <= n; i++) scanf(" %d", &height[i]);
	scanf(" %d", &m);
	v.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		scanf(" %d %d %d %d", &v[i].m, &v[i].t, &v[i].y, &v[i].x);
		map[v[i].y][v[i].x] = i;
	}
	scanf(" %d", &k);
	while (k--) {
		int u, a, b;
		scanf(" %d %d %d", &u, &a, &b);
		if (move(u, a, b)) {
			map[v[u].y][v[u].x] = 0;
			map[a][b] = u;
			v[u].y = a;
			v[u].x = b;
		}
	}
	for (int i = 1; i <= m; i++) printf("%d %d\n", v[i].y, v[i].x);
	return 0;
}