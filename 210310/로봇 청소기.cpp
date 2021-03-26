#include <iostream>
#include <queue>

using namespace std;

int n, m, map[50][50], dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
struct ROBOT {
	int y, x, d;
};
ROBOT robot;

int main() {
	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<ROBOT> q;
	q.push(robot);
	int ret = 0;
	while (!q.empty()) {
		ROBOT cur = q.front(); q.pop();
		if (map[cur.y][cur.x] == 0) {
			map[cur.y][cur.x] = 2;
			ret++;
		}
		for (int dir = 0; dir < 4; dir++) {
			ROBOT next;
			next.d = (cur.d + 3 - dir) % 4;
			next.y = cur.y + dy[next.d];
			next.x = cur.x + dx[next.d];
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] != 0)continue;
			q.push(next);
			break;
		}
		if (q.empty()) {
			ROBOT next;
			next.d = cur.d;
			next.y = cur.y + dy[(cur.d + 2) % 4];
			next.x = cur.x + dx[(cur.d + 2) % 4];
			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1)continue;
			q.push(next);

		}
	}
	cout << ret;
}

