#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int pane[102][102];
int visit[102][102];
int N;
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pane[i][j]=-1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 99999999;
		}
	}
}
void read() {
	scanf("%d", &N);
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &pane[i][j]);
		}
	}
}
int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };

void BFS() {
	queue<vector<int>> myway;//0,0,방향,속도
	int time = 0;
	visit[0][0] = 0;
	vector<int >start1 = { 1, 0, 1, 1 };
	vector<int >start2 = { 0, 1, 3, 1 };
	myway.push(start1);
	myway.push(start2);

	int min = 0x3f3f3f3f;
	while (!myway.empty()) {
		queue< vector<int>> tmp_q;
		while (!myway.empty()) {
			tmp_q.push(myway.front());
			myway.pop();
		}
		int dest_x, dest_y,velocity;
		
		while (!tmp_q.empty()) {
			time++;
			vector<int> tmp = tmp_q.front();
			for (int t = 0; t < 4; t++) {
				cout << tmp[t] <<" ";
			}
			cout << endl;

			tmp_q.pop();
			for (int i = 0; i < 4; i++) {
				if (tmp[2] == i) {//방향이 같음
					dest_x = tmp[0] + dir_x[i] * (tmp[3] + 1);
					dest_y = tmp[1] + dir_y[i] * (tmp[3] + 1);
					velocity = tmp[3] + 1;
				}
				else {
					dest_x = tmp[0] + dir_x[i];
					dest_y = tmp[1] + dir_y[i];
					velocity = 1;
				}

				if (dest_x == N - 1 && dest_y == N - 1) {//도착
					if (min > time) {
						min = time;
					}
					continue;
				}
				if (dest_x<0 || dest_x > N-1 || dest_y<0 ||dest_y > N-1) {//out of matrix
					continue;
				}
				if (visit[dest_x][dest_y] <= time) {
					continue;
				}
				vector<int>node = { dest_x,dest_y,i,velocity };
				cout << "    ";
				for (int t = 0; t < 4; t++) {
					cout << node[t]<<" ";
				}
				cout << endl;
				visit[dest_x][dest_y] = time;
				myway.push(node);
			}
		}
	}
	if (min == 0x3f3f3f3f) {
		cout << "Fired";
	}
	else {
		cout << min;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	read();
	BFS();
	return 0;
}