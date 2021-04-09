// 모노미노도미노 2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int n, total = 0, total_cnt = 0;
int arr[2][6][4]; // 0: green, 1: blue

void is_overflow() {
	for (int idx = 0; idx < 2; idx++) {
		int down_cnt = 0;
		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < 4; x++) {
				if (arr[idx][y][x]) {
					down_cnt++;
					break;
				}
			}
		}
		if (!down_cnt) continue;

		for (int y = 5 - down_cnt; y >= 0; y--) {
			for (int x = 0; x < 4; x++) {
				arr[idx][y + down_cnt][x] = arr[idx][y][x];
				arr[idx][y][x] = 0;
			}
		}
	}
}

void is_full() {
	for (int idx = 0; idx < 2; idx++) {
		for (int y = 5; y > 1; y--) {
			int block_cnt = 0;
			for (int x = 0; x < 4; x++)
				if (arr[idx][y][x]) block_cnt++;

			if (block_cnt != 4) continue;
			for (int _y = y - 1; _y >= 0; _y--) {
				for (int _x = 0; _x < 4; _x++) {
					arr[idx][_y + 1][_x] = arr[idx][_y][_x];
					arr[idx][_y][_x] = 0;
				}
			}
			y++;
			total++;
		}
	}
}

void put_1by1(int& x, int idx) {
	int y = 0;
	while (true) {
		if (y == 6 || arr[idx][y][x]) {
			arr[idx][y - 1][x] = 1;
			break;
		}
		y++;
	}
}

void put_1by2(int& x, int idx) {
	int y = 0, xx = x + 1;
	while (true) {
		if (y == 6 || arr[idx][y][x] || arr[idx][y][xx]) {
			arr[idx][y - 1][x] = 1;
			arr[idx][y - 1][xx] = 1;
			break;
		}
		y++;
	}
}

void put_2by1(int& x, int idx) {
	int y = 0;
	while (true) {
		if (y == 6 || arr[idx][y][x]) {
			arr[idx][y - 2][x] = 1;
			arr[idx][y - 1][x] = 1;
			break;
		}
		y++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int type, y, x;
		scanf(" %d %d %d", &type, &y, &x);
		switch (type)
		{
		case 1:
			put_1by1(x, 0);
			put_1by1(y, 1);
			break;
		case 2:
			put_1by2(x, 0);
			put_2by1(y, 1);
			break;
		case 3:
			put_2by1(x, 0);
			put_1by2(y, 1);
			break;
		}
		is_full();
		is_overflow();
	}
	for (int idx = 0; idx < 2; idx++) 
		for (int y = 2; y < 6; y++)
			for (int x = 0; x < 4; x++)
				if (arr[idx][y][x])
					total_cnt++;
	printf("%d\n%d\n", total, total_cnt);
	return 0;
}