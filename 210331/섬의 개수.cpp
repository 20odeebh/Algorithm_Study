#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int Width, Height;
int arr[51][51];
int visit[51][51];
int dirRow[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dirCol[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int answer = 0;
void bfs(int row, int col, int num)
{
	queue<pair<int, int>> q;
	q.push({ row, col });
	visit[row][col] = num;
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= Height || nc >= Width)
				continue;
			if (arr[nr][nc] == 1 && visit[nr][nc] == 0) {
				visit[nr][nc] = num;
				q.push({ nr, nc });
			}
		}
	}
	answer++;
}
int main()
{
	while (1) {
		answer = 0;
		cin >> Width >> Height;
		if (Width == 0 && Height == 0)
			break;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < Height; i++)
			for (int j = 0; j < Width; j++)
				cin >> arr[i][j];
		int num = 1;
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				if (arr[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j, num++);
				}
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}