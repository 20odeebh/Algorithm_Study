#include<bits/stdc++.h>

using namespace std;

int R, C, end_x, end_y, dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0 ,0 };
char arr[51][51];
bool visit[51][51] = { false, };
queue<pair<int, int>> water, start;

int bfs() {
	int cnt = 0;
	
	while (!start.empty()) {
		cnt++;
		int water_size = water.size();
		
		while (water_size--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (arr[nx][ny] == 'X' || arr[nx][ny] == 'D' || arr[nx][ny] == '*') continue;
				water.push(make_pair(nx, ny));
				arr[nx][ny] = '*';
			}
		}

		int start_size = start.size();
		while (start_size--) {
			int x = start.front().first;
			int y = start.front().second;
			start.pop();

			visit[x][y] = true;
			if (x == end_x && y == end_y) {
				cout << cnt - 1 << endl;
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (arr[nx][ny] == 'X' || arr[nx][ny] == '*' || visit[nx][ny]) continue;
				visit[nx][ny] = true;
				start.push(make_pair(nx, ny));
			}
		}
	}
	cout << "KAKTUS" << endl;
	return 0;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') start.push(make_pair(i, j));
			if (arr[i][j] == 'D') { end_x = i; end_y = j; }
			if (arr[i][j] == '*') water.push(make_pair(i, j));
		}
	}
	bfs();
}
