// 연구소

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

int n, m, cnt = 0, res = 0;
int arr[9][9];
bool visited[9][9];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
std::vector<std::pair<int, int>> v, wall;

void bfs() {
	memset(visited, false, sizeof(visited));
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(std::make_pair(v[i].first, v[i].second));
		visited[v[i].first][v[i].second] = true;
	}
	int cnt = wall.size() - 3;
	int y, x, ny, nx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny == n || nx < 0 || nx == m || visited[ny][nx] || arr[ny][nx]) continue;
			q.push(std::make_pair(ny, nx));
			visited[ny][nx] = true;
			cnt--;
		}
		if (res >= cnt) return;
	}
	res = std::max(res, cnt);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) v.push_back(std::make_pair(i, j));
			else if (!arr[i][j]) wall.push_back(std::make_pair(i, j));
		}
	}
	std::vector<int> tmp(wall.size(), 0);
	tmp[wall.size() - 3] = 1;
	tmp[wall.size() - 2] = 1;
	tmp[wall.size() - 1] = 1;
	do {
		for (int i = 0; i < wall.size(); i++) if (tmp[i]) arr[wall[i].first][wall[i].second] = 1;
		bfs();
		for (int i = 0; i < wall.size(); i++) if (tmp[i]) arr[wall[i].first][wall[i].second] = 0;
	} while (std::next_permutation(tmp.begin(), tmp.end()));

	printf("%d\n", res);
	return 0;
}