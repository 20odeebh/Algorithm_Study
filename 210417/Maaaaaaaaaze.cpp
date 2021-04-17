// Maaaaaaaaaze

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>

using namespace std;

int ret = INT_MAX;
int arr[5][5][5], copy_arr[5][5][5], tmp[5][5];
bool sequence[5], visited[5][5][5];
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
struct Point {
	int z, y, x;
};

void copy_array(int from, int to) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[to][i][j] = copy_arr[from][i][j];
}

void rotate(int idx) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = arr[idx][i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[idx][i][j] = tmp[4 - j][i];
}

int bfs() {
	if (!arr[0][0][0] || !arr[4][4][4]) return INT_MAX;
	memset(visited, false, sizeof(visited));
	queue<Point> q;
	q.push({ 0, 0, 0 });
	visited[0][0][0] = true;
	int y, x, z, ny, nx, nz, len, t = 0;
	while (!q.empty()) {
		if (++t == ret) return t;
		len = q.size();
		while (len--) {
			z = q.front().z;
			y = q.front().y;
			x = q.front().x;
			q.pop();
			for (int i = 0; i < 6; i++) {
				nz = z + dz[i];
				ny = y + dy[i];
				nx = x + dx[i];
				if (nz < 0 || nz == 5 || ny < 0 || ny == 5 || nx < 0 || nx == 5) continue;
				if (nz == 4 && ny == 4 && nx == 4) return t;
				if (visited[nz][ny][nx] || !arr[nz][ny][nx]) continue;
				q.push({ nz,ny,nx });
				visited[nz][ny][nx] = true;
			}
		}
	}
	return INT_MAX;
}

void dfs_2(int idx) {
	if (idx == 5) {
		int val = bfs();
		ret = ret > val ? val : ret;
		return;
	}
	for (int i = 0; i < 4; i++) {
		rotate(idx);
		dfs_2(idx + 1);
	}
}

void dfs_1(int idx) {
	if (idx == 5) {
		dfs_2(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!sequence[i]) {
			sequence[i] = true;
			copy_array(idx, i);
			dfs_1(idx + 1);
			sequence[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				scanf(" %d", &copy_arr[i][j][k]);
	dfs_1(0);
	if (ret == INT_MAX) ret = -1;
	printf("%d\n", ret);
	return 0;
}