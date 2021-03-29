#include <cstdio>

int main() {
	int r, c, t;
	int room[51][51];
	int cl;
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] == -1) {
				cl = i;
			}
		}
	}
	cl--;

	for (int time = 0; time<t; time++) {
		int exp[51][51] = {};
		for (int i = 0; i<r; i++) {
			for (int j = 0; j<c; j++) {
				if (room[i][j] != 0 && room[i][j] != -1) {
					int cnt = 0;
					for (int k = 0; k<4; k++) {
						int ay = i + dy[k], ax = j + dx[k];
						if (ay >= 0 && ay < r && ax >= 0 && ax < c && room[ay][ax] != -1) {
							cnt++;
							exp[ay][ax] += room[i][j] / 5;
						}
					}
					room[i][j] -= (room[i][j] / 5) * cnt;
				}
			}
		}
		for (int i = 0; i<r; i++) {
			for (int j = 0; j<c; j++) {
				room[i][j] += exp[i][j];
			}
		}

		for (int i = cl - 1; i >= 1; i--) {
			room[i][0] = room[i - 1][0];
		}
		for (int i = 0; i<c - 1; i++) {
			room[0][i] = room[0][i + 1];
		}
		for (int i = 0; i<cl; i++) {
			room[i][c - 1] = room[i + 1][c - 1];
		}
		for (int i = c - 1; i >= 1; i--) {
			room[cl][i] = room[cl][i - 1];
		}
		room[cl][1] = 0;


		for (int i = cl + 2; i<r - 1; i++) {
			room[i][0] = room[i + 1][0];
		}
		for (int i = 0; i<c - 1; i++) {
			room[r - 1][i] = room[r - 1][i + 1];
		}
		for (int i = r - 1; i>cl + 1; i--) {
			room[i][c - 1] = room[i - 1][c - 1];
		}
		for (int i = c - 1; i >= 1; i--) {
			room[cl + 1][i] = room[cl + 1][i - 1];
		}
		room[cl + 1][1] = 0;
	}

	int sum = 2; 
	for (int i = 0; i<r; i++) {
		for (int j = 0; j<c; j++) {
			sum += room[i][j];
		}
	}
	printf("%d", sum);

	return 0;
}
