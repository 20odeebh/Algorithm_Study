// 봄버맨

#include <stdio.h>
#include <string.h>
#include <queue>

int r, c, n;
char arr[201][201];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void boom() {
	int t = 0;
	std::queue<std::pair<int, int>> q;
	while (t < n) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (arr[i][j] == 'O') q.push(std::make_pair(i, j));
		if (++t == n) break;

		memset(arr, 'O', sizeof(arr));
		if (++t == n) break;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			arr[y][x] = '.';
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny == r || nx < 0 || nx == c) continue;
				arr[ny][nx] = '.';
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &r, &c, &n);
	for (int i = 0; i < r; i++) scanf("%s", arr[i]);

	if (n % 2 == 0) memset(arr, 'O', sizeof(arr));
	else boom();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}