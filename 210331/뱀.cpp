#include <iostream>
#include <deque>
using namespace std;
int N, K, L;
int arr[101][101];
deque<pair<int, char>> order;
deque<pair<int, int>> snake;
pair<int, int> nextPos(int dir)
{
	pair<int, int> p;
	switch (dir) {
	case 0:
		p.first = -1, p.second = 0;
		break;
	case 1:
		p.first = 0, p.second = 1;
		break;
	case 2:
		p.first = 1, p.second = 0;
		break;
	case 3:
		p.first = 0, p.second = -1;
		break;
	}
	return p;
}
int sim()
{
	int time = 0, r, c, nr, nc;
	int d = 1;
	while (1) {
		time++;
		r = snake.front().first;
		c = snake.front().second;

		nr = r + nextPos(d).first;
		nc = c + nextPos(d).second;
		if ((nr <= 0 || nc <= 0 || nr > N || nc > N) ||
			arr[nr][nc] == 1) {
			break;
		}
		else if (arr[nr][nc] == 2) {
			snake.push_front({ nr, nc });
			arr[nr][nc] = 1;
		}
		else {
			arr[snake.back().first][snake.back().second] = 0;
			arr[nr][nc] = 1;
			snake.push_front({ nr, nc });
			snake.pop_back();
		}
		if (!order.empty() && order.front().first == time) {
			switch (order.front().second) {
			case 'D':
				d = (d + 1) % 4;
				break;
			case 'L':
				d = (d + 3) % 4;
				break;
			}
			order.pop_front();
		}
	}
	return time;
}
int main()
{
	cin >> N >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		arr[r][c] = 2;
	}
	cin >> L;
	pair<int, char> o;
	for (int i = 0; i < L; i++) {
		cin >> o.first >> o.second;
		order.push_back(o);
	}
	snake.push_back({ 1, 1 });
	arr[1][1] = 1;
	printf("%d\n", sim());
	return 0;
}