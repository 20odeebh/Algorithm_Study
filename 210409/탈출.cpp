#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 50
int R, C;
char arr[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
queue<pair<int, int>> water;
queue<pair<int, int>> sq;
pair<int, int> goal;
bool IsRange(int row, int col)
{
	if (row < 0 || col < 0 || row >= R || col >= C)
		return false;
	return true;
}
bool IsArrive(int row, int col)
{
	if (row == goal.first && col == goal.second)
		return true;
	return false;
}
void game()
{
	int wsize, ssize, time = 0;
	int r, c, nr, nc;
	do {
		time++;
		wsize = water.size();
		for (int i = 0; i < wsize; i++) {
			r = water.front().first;
			c = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				nr = r + dirRow[j];
				nc = c + dirCol[j];
				if (!IsRange(nr, nc))
					continue;
				if (arr[nr][nc] == '.' || arr[nr][nc] == 'S') {
					arr[nr][nc] = '*';
					water.push({ nr, nc });
				}
			}
		}

		ssize = sq.size();
		for (int i = 0; i < ssize; i++) {
			r = sq.front().first;
			c = sq.front().second;
			sq.pop();
			for (int j = 0; j < 4; j++) {
				nr = r + dirRow[j];
				nc = c + dirCol[j];
				if (!IsRange(nr, nc))
					continue;
				if (IsArrive(nr, nc)) {
					printf("%d\n", time);
					return;
				}
				if (arr[nr][nc] == '.') {
					arr[nr][nc] = 'S';
					sq.push({ nr, nc });
				}
			}
		}

	} while (wsize != 0 || ssize != 0);
	printf("KAKTUS\n");
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*')
				water.push({ i, j });
			if (arr[i][j] == 'S')
				sq.push({ i, j });
			if (arr[i][j] == 'D') {
				goal.first = i;
				goal.second = j;
			}
		}
	game();
	return 0;
}