// 주사위 굴리기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int n, m, x, y, k;
int arr[21][21];
int dice[6];
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void move(int& d) {
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (ny < 0 || ny == n || nx < 0 || nx == m) return;
	y = ny;
	x = nx;

	int next_dice[6];
	std::copy(dice, dice + 6, next_dice);

	switch (d)
	{
	case 1:
		dice[0] = next_dice[2];
		dice[2] = next_dice[5];
		dice[5] = next_dice[3];
		dice[3] = next_dice[0];
		break;
	case 2:
		dice[0] = next_dice[3];
		dice[2] = next_dice[0];
		dice[3] = next_dice[5];
		dice[5] = next_dice[2];
		break;
	case 3:
		dice[0] = next_dice[1];
		dice[1] = next_dice[5];
		dice[4] = next_dice[0];
		dice[5] = next_dice[4];
		break;
	case 4:
		dice[0] = next_dice[4];
		dice[1] = next_dice[0];
		dice[4] = next_dice[5];
		dice[5] = next_dice[1];
		break;
	}

	if (arr[y][x]) {
		dice[5] = arr[y][x];
		arr[y][x] = 0;
	}
	else {
		arr[y][x] = dice[5];
	}
	printf("%d\n", dice[0]);
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = 0; i < k; i++) {
		int input;
		scanf(" %d", &input);
		move(input);
	}
	return 0;
}