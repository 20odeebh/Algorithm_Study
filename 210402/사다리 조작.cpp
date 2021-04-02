// 사다리 조작 

#include <stdio.h>

 int n, m, h, lain = 1, res = -1;
 int arr[31][11][2] = { { {0,},}, };
 int dy[3] = { 1, 0, 0 };
 int dx[3] = { 0, 1, -1 };

 bool game() {
 	int y, x, d, ny, nx;
 	for (int i = 1; i <= n; i++) {
 		y = 1;
 		x = i;
 		d = 0;
 		while (true) {
 			if (arr[y][x][0] == 0) y++;
 			else {
 				if (d == 0) {
 					d = arr[y][x][1];
 					x += dx[d];
 				}
 				else {
 					d = 0;
 					y++;
 				}
 			}
 			if (y == h + 1) {
 				if (x == i) break;
 				else return false;
 			}
 		}
 	}
 	return true;
 }

 void dfs(int y, int x, int cnt) {
 	if (res != -1) return;
 	if (cnt == lain) {
 		if (game()) res = lain;
 		return;
 	}
 	if (y > h) return;
 	if (x >= n) {
 		dfs(y + 1, 1, cnt);
 		return;
 	}
 	if (arr[y][x][0]) {
 		if (arr[y][x][1] == 1) dfs(y, x + 2, cnt);
 		else dfs(y, x + 1, cnt);
 		return;
 	}
 	else {
 		if (arr[y][x + 1][0]) dfs(y, x + 3, cnt);
 		else {
 			arr[y][x][0] = 1;     arr[y][x][1] = 1;
 			arr[y][x + 1][0] = 1; arr[y][x + 1][1] = 2;
 			dfs(y, x + 2, cnt + 1);
 			arr[y][x][0] = 0;     arr[y][x][1] = 0;
 			arr[y][x + 1][0] = 0; arr[y][x + 1][1] = 0;
 			dfs(y, x + 1, cnt);
 		}
 	}
 }

 int main() {
 	int y, x;
	scanf("%d %d %d", &n, &m, &h);
 	while (m--) {
		scanf(" %d %d", &y, &x);
 		arr[y][x][0] = 1;
 		arr[y][x][1] = 1;
 		arr[y][x + 1][0] = 1;
 		arr[y][x + 1][1] = 2;
 	}
 	if (game()) res = 0;
 	while (res == -1) {
 		dfs(0, 0, 0);
 		if (lain++ == 3) break;
 	}
	printf("%d\n", res);
 	return 0;
 }