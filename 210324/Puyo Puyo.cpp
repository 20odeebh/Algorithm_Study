#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
#define HEIGHT 13
#define WIDTH 7
char arr[HEIGHT][WIDTH];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
bool bfs(int row, int col, queue<pair<int, int>>& rmq)
{
	bool visit[HEIGHT][WIDTH];
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q, tq;
	q.push({ row, col });
	visit[row][col] = true;
	int cnt = 1;
	char ch = arr[row][col];
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 1 || nc < 1 || nr >= HEIGHT || nc >= WIDTH)
				continue;
			if (arr[nr][nc] == ch && !visit[nr][nc]) {
				visit[nr][nc] = true;
				q.push({ nr, nc });
				cnt++;
				tq.push({ nr, nc });
			}
		}
	}
	if (cnt >= 4) {
		while (!tq.empty()) {
			rmq.push(tq.front());
			tq.pop();
		}
		return true;
	}
	return false;
}
void remove(queue<pair<int, int>>& rmq)
{
	int r, c;
	while (!rmq.empty()) {
		r = rmq.front().first;
		c = rmq.front().second;
		rmq.pop();
		arr[r][c] = '.';
	}
	stack<char> s;
	int idx;
	for (int c = 1; c < WIDTH; c++) {
		for (int r = 1; r < HEIGHT; r++) {
			if ('A' <= arr[r][c] && arr[r][c] <= 'Z')
				s.push(arr[r][c]);
		}
		for (int r = HEIGHT - 1; r >= 0; r--) {
			if (!s.empty()) {
				arr[r][c] = s.top();
				s.pop();
			}
			else {
				arr[r][c] = '.';
			}
		}
	}
}
int main()
{
	string str;
	for (int i = 1; i < HEIGHT; i++) {
		cin >> str;
		for (int j = 1; j <= str.length(); j++) {
			arr[i][j] = str[j - 1];
		}
	}
	queue<pair<int, int>> rmq;
	bool done = true;
	int time = 0;
	do {
		done = true;
		for (int i = 1; i < HEIGHT; i++) {
			for (int j = 1; j < WIDTH; j++) {
				if (arr[i][j] != '.' && bfs(i, j, rmq)) {
					done = false;
				}
			}
		}
		remove(rmq);
		if (!done)
			time++;
	} while (!done);
	printf("%d\n", time);
	return 0;
}