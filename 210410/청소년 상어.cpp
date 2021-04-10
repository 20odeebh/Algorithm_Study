// 청소년 상어

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int res = 0;
int arr[4][4];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

struct FISH {
	bool die;
	int y, x, d;
};
FISH fish[17];

void move_fish() {
	for (int idx = 1; idx <= 16; idx++) {
		if (fish[idx].die) continue;
		int y = fish[idx].y;
		int x = fish[idx].x;
		int d = fish[idx].d;
		while (true) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny == 4 || nx < 0 || nx == 4 || arr[ny][nx] == 100) {
				d = (d + 1) % 8;
				continue;
			}
			fish[idx].d = d;
			if (arr[ny][nx]) {
				swap(fish[idx].y, fish[arr[ny][nx]].y);
				swap(fish[idx].x, fish[arr[ny][nx]].x);
			}
			else fish[idx].y = ny, fish[idx].x = nx;
			swap(arr[y][x], arr[ny][nx]);
			break;
		}
	}
}

void shark(int y, int x, int total) {
	total += arr[y][x];
	res = max(res, total);

	int d = fish[arr[y][x]].d;
	fish[arr[y][x]].die = true;
	arr[y][x] = 100;
	move_fish();

	FISH tmp[17];
	for (int i = 1; i < 17; i++) tmp[i] = fish[i];

	for (int move = 1; move <= 3; move++) {
		int ny = y + (dy[d] * move);
		int nx = x + (dx[d] * move);
		if (ny < 0 || ny == 4 || nx < 0 || nx == 4) return;
		if (!arr[ny][nx]) continue;
		arr[y][x] = 0;
		shark(ny, nx, total);

		memset(arr, 0, sizeof(arr));
		arr[y][x] = 100;
		for (int i = 1; i < 17; i++) {
			fish[i] = tmp[i];
			if (!fish[i].die)
				arr[fish[i].y][fish[i].x] = i;
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, d;
			scanf(" %d %d", &num, &d);
			arr[i][j] = num;
			fish[num] = { false, i, j, d - 1 };
		}
	}
	shark(0, 0, 0);
	printf("%d\n", res);
	return 0;
}