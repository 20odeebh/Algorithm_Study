// 벽돌 깨기

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>

using namespace std;

int test_case, n, w, h, ball_cnt, res;
int arr[16][13];
int tmp_arr[16][13];
int ball[4];

struct Point {
	int y, x, val;
};
Point p[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void falling_map() {
	int y, idx, val;
	for (int x = 0; x < w; x++) {
		y = h - 1;
		idx = h - 1;
		while (y >= 0) {
			if (arr[y][x]) {
				val = arr[y][x];
				arr[y][x] = 0;
				arr[idx--][x] = val;
			}
			y--;
		}
	}
}

void break_map(int _y, int _x) {
	queue<Point> q;
	q.push({ _y, _x, arr[_y][_x] });
	arr[_y][_x] = 0;
	ball_cnt--;
	int y, x, ny, nx, val;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		val = q.front().val;
		q.pop();
		for (int i = 1; i < val; i++) {
			for (int j = 0; j < 4; j++) {
				ny = y + (p[j].y * i);
				nx = x + (p[j].x * i);
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && arr[ny][nx]) {
					if (arr[ny][nx] > 1)
						q.push({ ny, nx, arr[ny][nx] });
					arr[ny][nx] = 0;
					ball_cnt--;
				}
			}
		}
	}
	falling_map();
}

void falling_ball() {
	int y, x;
	int tmp_cnt = ball_cnt;
	for (int i = 0; i < n; i++) {
		y = 0;
		x = ball[i];
		while (y != h) {
			if (arr[y][x]) {
				if (arr[y][x] == 1) {
					ball_cnt--;
					arr[y][x] = 0;
					break;
				}
				break_map(y, x);
				break;
			}
			y++;
		}
	}
	res = res > ball_cnt ? ball_cnt : res;
	ball_cnt = tmp_cnt;
}

void copy_arr() {
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			arr[i][j] = tmp_arr[i][j];
}

void dfs(int cnt) {
	if (!res) return;
	if (cnt == n) {
		falling_ball();
		copy_arr();
		return;
	}
	for (int i = 0; i < w; i++) {
		ball[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = INT_MAX;
		ball_cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(tmp_arr, 0, sizeof(tmp_arr));
		scanf(" %d %d %d", &n, &w, &h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf(" %d", &arr[i][j]);
				tmp_arr[i][j] = arr[i][j];
				if (arr[i][j]) ball_cnt++;
			}
		}
		dfs(0);
		printf("#%d %d\n", tc, res);
	}
	return 0;
}