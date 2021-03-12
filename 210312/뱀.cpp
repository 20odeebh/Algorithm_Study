#include <iostream>
#include <queue>

#define APPLE 2
#define SNAKE 1
#define LEFT 3
#define RIGHT 1

using namespace std;

int N, K, L, time = 0;
int dx[4] = { -1,0,1,0 },dy[4] = { 0,1,0,-1 };
int map[102][102] = { 0, }, apple[102][102] = { 0, };
int t[10001] = { 0, };
int headX, headY, tailX, tailY, dir;
queue<pair<int, int>> q;

void solve(void) {

	int nextX = headX, nextY = headY;
	q.push({ 1,1 });

	while (1) {

		time++;
		nextX = headX + dx[dir];
		nextY = headY + dy[dir];
		if (map[nextX][nextY] == SNAKE) {
			break;
		}
		if (nextX > N || nextX < 1 || nextY > N || nextY < 1) break;
		headX = nextX;
		headY = nextY;
		map[headX][headY] = SNAKE;
		q.push(make_pair(headX, headY));

		if (apple[headX][headY] == APPLE) {
			apple[headX][headY] = 0;
		}
		else {
			tailX = q.front().first;
			tailY = q.front().second;
			map[tailX][tailY] = 0;
			q.pop();
		}

		if (t[time] == LEFT) {
			if (dir == 0) dir = 3;
			else dir = dir - 1;
		}
		else if (t[time] == RIGHT) {
			if (dir == 3) dir = 0;
			else dir = dir + 1;
		}
	}
}
void init(void) {

	cin >> N >> K;
	for (int i = 0, a, b; i < K; i++) {
		cin >> a >> b;
		apple[a][b] = APPLE;
	}

	cin >> L;
	int a = 0; char b = NULL;
	for (int i = 0; i < L; i++) {
		cin >> a >> b;
		if (b == 'L') t[a] = LEFT;
		else t[a] = RIGHT;
	}

	dir = 1, headX = 1, headY = 1, tailX = 1, tailY = 1;
	map[1][1] = SNAKE;
}
int main(void) {

	init();
	solve();
	cout << time << endl;
	return 0;
}
