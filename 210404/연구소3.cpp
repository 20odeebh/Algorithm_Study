// 연구소 3

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, empty_cnt = 0, res = INT_MAX;
int arr[51][51];
bool visited[51][51];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<int> virus;
vector<pair<int, int>> v;

int bfs() {
	int y, x, ny, nx, len, t = 0, cnt = 0;
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		y = v[virus[i]].first;
		x = v[virus[i]].second;
		q.push(make_pair(y, x));
		visited[y][x] = true;
	}
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || visited[ny][nx] || arr[ny][nx] == 1) continue;
				if (arr[ny][nx] == 0) cnt++;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
			if (cnt == empty_cnt) return t;
		}
		if (t >= res) break;
	}
	return INT_MAX;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		int t = bfs();
		res = min(res, t);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		virus.push_back(i);
		dfs(i + 1, cnt + 1);
		virus.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 0) empty_cnt++;
			else if (arr[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}
	if (empty_cnt == 0) {
		printf("0\n");
		return 0;
	}
	dfs(0, 0);
	if (res == INT_MAX) res = -1;
	printf("%d\n", res);
	return 0;
}