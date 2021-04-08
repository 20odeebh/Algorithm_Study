#include <iostream>
#include <queue>
using namespace std;
int R, C, N;
char arr[200][200];
queue<pair<int, int>> bomb;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
void Print()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}
void SearchBomb()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'O') {
				bomb.push({ i, j });
			}
		}
	}
}
void SetBomb()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '.')
				arr[i][j] = 'O';
		}
	}
}
void explode(queue<pair<int, int>>& q)
{
	while (!q.empty()) {
		auto r = q.front().first;
		auto c = q.front().second;
		int nr, nc;
		arr[r][c] = '.';
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C)
				continue;
			arr[nr][nc] = '.';
		}
		q.pop();
	}
}
int main()
{
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	int timer = N - 1, interval = 0;
	while (timer--) {
		interval++;
		if (interval % 2 == 1) {
			SearchBomb();
			//Æø¼³
			SetBomb();
		}
		else {
			//ÆøÅº ÅÍÁü
			explode(bomb);
		}
	}
	Print();
	return 0;
}