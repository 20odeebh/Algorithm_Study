#include <bits/stdc++.h>

using namespace std;

int N, visited[100][100][100][100];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

vector<vector<int>> boards;

struct robot {
	int x1;
	int y1;
	int x2;
	int y2;
	int direction;
	int count;

	robot(int _x1, int _y1, int _x2, int _y2, int _direction, int _count) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		direction = _direction;
		count = _count;
	}
};

bool checkMove(robot bot) {
	if (bot.x1 < 0 || bot.y1 < 0 || bot.x2 < 0 || bot.y2 < 0) return false;
	if (bot.x1 >= N || bot.y1 >= N || bot.x2 >= N || bot.y2 >= N) return false;
	if (boards[bot.x1][bot.y1] == 1 || boards[bot.x2][bot.y2] == 1) return false;
	if (visited[bot.x1][bot.y1][bot.x2][bot.y2] == 1) return false;
	if (visited[bot.x2][bot.y2][bot.x1][bot.y1] == 1) return false;
	return true;
}

bool checkRotate(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return false;
	if (x1 >= N || y1 >= N || x2 >= N || y2 >= N) return false;
	if (boards[x1][y1] == 1 || boards[x2][y2] == 1) return false;
	return true;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	boards = board;

	queue<robot> q;

	robot start(0, 0, 0, 1, 0, 0);

	q.push(start);

	while (!q.empty()) {
		robot now = q.front();
		q.pop();

		
		if (now.x1 == N - 1 && now.y1 == N - 1) return now.count;
		if (now.x2 == N - 1 && now.y2 == N - 1) return now.count;

		visited[now.x1][now.y1][now.x2][now.y2] = 1;
		visited[now.x2][now.y2][now.x1][now.y1] = 1;

		
		for (int i = 0; i < 4; i++) {
			robot next(now.x1 + dir[i][0], now.y1 + dir[i][1], now.x2 + dir[i][0], now.y2 + dir[i][1], now.direction, now.count + 1);
			if (checkMove(next)) {
				visited[next.x1][next.y1][next.x2][next.y2] = 1;
				visited[next.x2][next.y2][next.x1][next.y1] = 1;
				q.push(next);
			}
		}

		
		if (now.direction == 0) {
			for (int i = 1; i < 4; i += 2) {
                
				if (checkRotate(now.x1 + dir[i][0], now.y1 + dir[i][1], now.x2 + dir[i][0], now.y2 + dir[i][1])) {
                    
					if (!visited[now.x1][now.y1][now.x1 + dir[i][0]][now.y1 + dir[i][1]]) {
						robot next(now.x1, now.y1, now.x1 + dir[i][0], now.y1 + dir[i][1], 1, now.count + 1);
						visited[next.x1][next.y1][next.x2][next.y2] = 1;
						visited[next.x2][next.y2][next.x1][next.y1] = 1;
						q.push(next);
					}
                    
					if (!visited[now.x2][now.y2][now.x2 + dir[i][0]][now.y2 + dir[i][1]]) {
						robot next(now.x2, now.y2, now.x2 + dir[i][0], now.y2 + dir[i][1], 1, now.count + 1);
						visited[next.x1][next.y1][next.x2][next.y2] = 1;
						visited[next.x2][next.y2][next.x1][next.y1] = 1;
						q.push(next);
					}
				}
			}
		}
		
		else if (now.direction == 1) {
			for (int i = 0; i < 3; i += 2) {
              
				if (checkRotate(now.x1 + dir[i][0], now.y1 + dir[i][1], now.x2 + dir[i][0], now.y2 + dir[i][1])) {
                    
					if (!visited[now.x1][now.y1][now.x1 + dir[i][0]][now.y1 + dir[i][1]]) {
						robot next(now.x1, now.y1, now.x1 + dir[i][0], now.y1 + dir[i][1], 0, now.count + 1);
						visited[next.x1][next.y1][next.x2][next.y2] = 1;
						visited[next.x2][next.y2][next.x1][next.y1] = 1;
						q.push(next);
					}
                  
					if (!visited[now.x2][now.y2][now.x2 + dir[i][0]][now.y2 + dir[i][1]]) {
						robot next(now.x2, now.y2, now.x2 + dir[i][0], now.y2 + dir[i][1], 0, now.count + 1);
						visited[next.x1][next.y1][next.x2][next.y2] = 1;
						visited[next.x2][next.y2][next.x1][next.y1] = 1;
						q.push(next);
					}
				}
			}
		}
	}
	return -1;
}