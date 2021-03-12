#include <iostream>
#include <queue>
#include <deque>
using namespace std;
int N, L;
int BoardSize;
int board[101][101];
queue<pair<int, char>> q;
deque<pair<int, int>> snake;
//¿À¸¥ÂÊ +3, ¿Þ +1
pair<int, int> nextPos(int dir, int row, int col)
{
	switch (dir) {
	case 0://¿À¸¥
		return { row, col + 1 };
	case 1://À§
		return { row - 1, col };
	case 2: //¿Þ
		return { row, col - 1 };
	case 3: //¾Æ·¡
		return { row + 1, col };
	}
}
int PlayGame()
{
	int time = 0, dir = 0;
	char d;
	int nr, nc;
	board[1][1] = 1;
	snake.push_back({ 1, 1 });
	while (1) {
		time++;
		pair<int, int> next = nextPos(dir, snake.front().first, snake.front().second);
		nr = next.first;
		nc = next.second;
		if (board[nr][nc] == 2)
			snake.push_front({ nr, nc });
		else if (board[nr][nc] == 1)
			break;
		else if (nr <= 0 || nc <= 0 || nr > BoardSize || nc > BoardSize)
			break;
		else {
			snake.push_front({ nr, nc });
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		board[nr][nc] = 1;

		if (!q.empty() && time == q.front().first) {
			if (q.front().second == 'D') //¿À¸¥
				dir = (dir + 3) % 4;
			else if (q.front().second == 'L') //¿Þ
				dir = (dir + 1) % 4;
			q.pop();
		}
	}
	return time;
}
int main()
{
	cin >> BoardSize;
	int apple, row, col;
	cin >> apple;
	for (int i = 0; i < apple; i++) {
		cin >> row >> col;
		board[row][col] = 2;
	}
	cin >> L;
	int time, answer;
	char dir;
	for (int i = 0; i < L; i++) {
		cin >> time >> dir;
		q.push({ time, dir });
	}
	answer = PlayGame();
	printf("%d\n", answer);
	return 0;
}