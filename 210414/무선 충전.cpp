// 무선 충전

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int M, A, ay, ax, by, bx, res;
int move_a[101], move_b[101];
bool visited_a[10], visited_b[10];
int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };

struct Point {
	int y, x, c, p;
}BC[9];

void charge() {
	memset(visited_a, false, sizeof(visited_a));
	memset(visited_b, false, sizeof(visited_b));

	for (int i = 1; i <= A; i++) {
		int D = abs(BC[i].y - ay) + abs(BC[i].x - ax);
		if (D <= BC[i].c) visited_a[i] = true;
	}
	for (int i = 1; i <= A; i++) {
		int D = abs(BC[i].y - by) + abs(BC[i].x - bx);
		if (D <= BC[i].c) visited_b[i] = true;
	}

	int max_sum = 0;
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= A; j++) {
			if (!visited_a[i] && !visited_b[j]) continue;
			int tmp_sum = 0;

			if (i == j) tmp_sum += BC[i].p;
			else {
				if (visited_a[i]) tmp_sum += BC[i].p;
				if (visited_b[j]) tmp_sum += BC[j].p;
			}
			if (max_sum < tmp_sum) max_sum = tmp_sum;
		}
	}
	res += max_sum;
}

void move(int time) {
	ay += dy[move_a[time]];
	ax += dx[move_a[time]];
	by += dy[move_b[time]];
	bx += dx[move_b[time]];
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		res = 0;
		scanf(" %d %d", &M, &A);
		for (int i = 0; i < M; i++) scanf(" %d", &move_a[i]);
		for (int i = 0; i < M; i++) scanf(" %d", &move_b[i]);
		for (int i = 1; i <= A; i++) {
			int y, x, c, p;
			scanf(" %d %d %d %d", &x, &y, &c, &p);
			BC[i] = { y - 1, x - 1, c, p };
		}
		ay = 0, ax = 0;
		by = 9, bx = 9;
		for (int i = 0; i < M; i++) {
			charge();
			move(i);
		}
		charge();
		printf("#%d %d\n", tc, res);
	}
	return 0;
}