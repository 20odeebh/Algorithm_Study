#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n, res = 0;
int arr[21][21];
bool visited[21][21];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void copy_arr(int tmp[][21], bool flag) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag) tmp[i][j] = arr[i][j];
			else arr[i][j] = tmp[i][j];
		}
	}
}

void rotate_arr() {
	int tmp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = tmp[n - 1 - j][i];
}

void falling_arr() {
	memset(visited, false, sizeof(visited));
	int x, val;
	for (int y = 0; y < n; y++) {
		for (int nx = 1; nx < n; nx++) {
			if (!arr[y][nx]) continue;
			x = nx;
			val = arr[y][x];
			arr[y][x] = 0;
			while (true) {
				x += dx[1];
				if (x < 0) {
					x -= dx[1];
					arr[y][x] = val;
					break;
				}
				if (arr[y][x]) {
					if (arr[y][x] == val) {
						if (visited[y][x]) {
							x -= dx[1];
							arr[y][x] = val;
						}
						else {
							visited[y][x] = true;
							arr[y][x] <<= 1;
						}
					}
					else {
						x -= dx[1];
						arr[y][x] = val;
					}
					break;
				}
			}
		}
	}
}

void dfs(int cnt) {
	if (cnt == 5) {
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				val = max(val, arr[i][j]);
		res = max(res, val);
		return;
	}
	int tmp[21][21];
	for (int i = 0; i < 4; i++) {
		copy_arr(tmp, true);
		falling_arr();
		dfs(cnt + 1);
		copy_arr(tmp, false);
		rotate_arr();
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dfs(0);
	cout << res << '\n';
	return 0;
}