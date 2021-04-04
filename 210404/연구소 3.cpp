#include <iostream>
#include <queue>

using namespace std;


int n, m, ret;
int a[50][50];
struct POS {
	int y, x, time;
};
POS pos[10];
int posSize;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int bfs(int pick[]) {
	int zc = 0;
	queue<POS> q;
	int vis[50][50] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				zc++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		q.push(pos[pick[i]]);
		vis[pos[pick[i]].y][pos[pick[i]].x] = 1;
	}

	while (!q.empty()) {
		POS cur = q.front();
		q.pop();

		if (a[cur.y][cur.x] == 0)zc--;
		if (zc == 0)return cur.time;
		POS next;
		next.time = cur.time + 1;
		for (int i = 0; i < 4; i++) {
			next.y = cur.y + dy[i];
			next.x = cur.x + dx[i];
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)continue;
			if (vis[next.y][next.x] == 0 && a[next.y][next.x] != 1) {
				q.push(next);
				vis[next.y][next.x] = 1;
			}
		}
	}
	return 0x7fffffff;
}

void dfs(int last_pick, int pick_count, int pick[]) {
	if (pick_count == m) {
		int candi = bfs(pick);
		if (ret > candi)ret = candi;
		return;
	}
	for (int i = last_pick + 1; i < posSize; i++) {
		pick[pick_count] = i;
		dfs(i, pick_count + 1, pick);
		pick[pick_count] = 0;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				pos[posSize].y = i;
				pos[posSize].x = j;
				pos[posSize].time = 0;
				posSize++;
			}
		}
	}
	ret = 0x7fffffff;
	int pick[10] = { 0 };
	dfs(-1, 0, pick);
	if (ret == 0x7fffffff)cout << -1;
	else cout << ret;
}
