#include <iostream>
#include <queue>

using namespace std;

int N, K, L, time;
int dx[4] = { -1,0,1,0 },dy[4] = { 0,1,0,-1 };
int map[102][102], apple[102][102], t[10001];
int headX, headY, tailX, tailY, dir;

queue<pair<int, int>> q;

void solve(void) {
	int nextX = headX, nextY = headY;
	q.push({ 1,1 });

	while (true) {
		time++;
		nextX = headX + dx[dir];
		nextY = headY + dy[dir];
		
		if (map[nextX][nextY] == 1) {
			break;
		}
		
		if (nextX > N || nextX < 1 || nextY > N || nextY < 1) break;
		headX = nextX;
		headY = nextY;
		map[headX][headY] = 1;
		q.push(make_pair(headX, headY));

		if (apple[headX][headY] == 2) {
			apple[headX][headY] = 0;
		}
		else {
			tailX = q.front().first;
			tailY = q.front().second;
			map[tailX][tailY] = 0;
			q.pop();
		}

		if (t[time] == 3) {
			if (dir == 0) dir = 3;
			else dir = dir - 1;
		}
		else if (t[time] == 1) {
			if (dir == 3) dir = 0;
			else dir = dir + 1;
		}
	}
}

void init() {
	cin >> N >> K;
	for (int i = 0, a, b; i < K; i++) {
		cin >> a >> b;
		apple[a][b] = 2;
	}

	cin >> L;
	int a = 0; char b = NULL;
	for (int i = 0; i < L; i++) {
		cin >> a >> b;
		if (b == 'L') t[a] = 3;
		else t[a] = 1;
	}

	dir = 1, headX = 1, headY = 1, tailX = 1, tailY = 1;
	map[1][1] = 1;
}

int main() {
	init();
	solve();
    cout << time << endl;
}
