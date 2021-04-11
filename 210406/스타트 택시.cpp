// 스타트 택시

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int n, M, k;
int arr[21][21];
bool visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
map<pair<int, int>, pair<int, int>> m;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void init() {
	while (!q.empty()) q.pop();
	v.clear();
	memset(visited, false, sizeof(visited));
}

bool find_customer(int& y, int& x, int& k) {
	int ny, nx, len;
	init();
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty() && k) {
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			if (m.count(make_pair(y, x))) v.push_back(make_pair(y, x));
			else {
				for (int i = 0; i < 4; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] || visited[ny][nx]) continue;
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
		if (v.size()) break;
		k--;
	}

	if (v.empty()) {
		k = -1;
		return false;
	}
	return true;
}

bool find_destination(int& y, int& x, int& k) {
	int sy = y, sx = x;
	int ny, nx, len, distance = 0;
	init();
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty() && k) {
		k--;
		distance++;
		len = q.size();
		while (len--) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] || visited[ny][nx]) continue;
				if (m[make_pair(sy, sx)] == make_pair(ny, nx)) {
					y = ny;
					x = nx;
					k += distance * 2;
					m.erase(make_pair(sy, sx));
					return true;
				}
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}

	k = -1;
	return false;
}

void taxi(int y, int x) {
	int ny, nx, len, distance;
	while (true) {
		if (!find_customer(y, x, k)) break;
		sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
			if (p1.first < p2.first) return true;
			else if(p1.first == p2.first) {
				if (p1.second < p2.second) return true;
				else return false;
			}
			else return false;
		});
		y = v[0].first, x = v[0].second;
		if (!find_destination(y, x, k)) break;
		if (m.empty()) break;
	}
}

int main() {
	scanf("%d %d %d", &n, &M, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	int y, x;
	scanf(" %d %d", &y, &x);
	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;
		scanf(" %d %d %d %d", &y1, &x1, &y2, &x2);
		m[make_pair(y1 - 1, x1 - 1)] = make_pair(y2 - 1, x2 - 1);
	}
	taxi(y - 1, x - 1);
	printf("%d\n", k);
	return 0;
}