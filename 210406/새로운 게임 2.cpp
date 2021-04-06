// 새로운 게임 2

#include <stdio.h>
#include <deque>

using namespace std;

int n, k;
bool flag = false;
int arr[12][12];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
deque<int> dq[12][12];

struct Point {
	int y, x, d;
};
Point p[11];

int get_index(int& idx) {
	int index = 0;
	for (auto& it : dq[p[idx].y][p[idx].x]) {
		if (it == idx) break;
		index++;
	}
	return index;
}

void move_white(int& idx, int& y, int& x, int& ny, int& nx) {
	int len = dq[y][x].size();
	int index = get_index(idx);
	for (int i = index; i < len; i++) {
		p[dq[y][x][i]].y = ny;
		p[dq[y][x][i]].x = nx;
		dq[ny][nx].push_back(dq[y][x][i]);
	}
	for (int i = index; i < len; i++) dq[y][x].pop_back();
	if (dq[ny][nx].size() >= 4) flag = true;
}

void move_red(int& idx, int& y, int& x, int& ny, int& nx) {
	int len = dq[y][x].size();
	int index = get_index(idx);
	for (int i = 0; i < len - index; i++) {
		p[dq[y][x].back()].y = ny;
		p[dq[y][x].back()].x = nx;
		dq[ny][nx].push_back(dq[y][x].back());
		dq[y][x].pop_back();
	}
	if (dq[ny][nx].size() >= 4) flag = true;
}

void move_blue(int& idx, int& y, int& x, int& d) {
	int nd;
	if (d % 2) nd = d - 1;
	else nd = d + 1;
	p[idx].d = nd;
	int ny = y + dy[nd];
	int nx = x + dx[nd];
	if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) return;
	int index = get_index(idx);
	if (arr[ny][nx] == 0) move_white(idx, y, x, ny, nx);
	else move_red(idx, y, x, ny, nx);
}

int game() {
	int y, x, ny, nx, d, t = 0;
	while (t <= 1000) {
		t++;
		for (int i = 1; i <= k; i++) {
			y = p[i].y, x = p[i].x, d = p[i].d;
			ny = y + dy[d], nx = x + dx[d];
			if (ny < 0 || ny == n || nx < 0 || nx == n || arr[ny][nx] == 2) move_blue(i, y, x, d);
			else if (arr[ny][nx] == 0) move_white(i, y, x, ny, nx);
			else move_red(i, y, x, ny, nx);
			if (flag) return t;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 1; i <= k; i++) {
		int y, x, d;
		scanf(" %d %d %d", &y, &x, &d);
		p[i] = { y - 1,x - 1,d - 1 };
		dq[y - 1][x - 1].push_back(i);
	}
	printf("%d\n", game());
	return 0;
}