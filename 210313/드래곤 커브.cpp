#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_set>

using namespace std;
// 우상좌하
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int n;
bool visited[101][101];

void make_dragon(int x, int y, int d, int g) {
	// 끝점을 기준으로 90도 시계방향 회전 후 끝점에 이어붙임
	int ex, ey;
	ex = x, ey = y;
	// 0세대
	visited[x][y] = true;
	ex = x + dx[d], ey = y + dy[d];
	//cout << ex << ' ' << ey << endl;
	visited[ex][ey] = true;

	vector<int> dir;
	dir.push_back(d);

	while (g--) {
		for (int i = dir.size() - 1; i >= 0; i--) {
			// 시계방향
			int new_dir = (dir[i] + 1) % 4;
			ex = ex + dx[new_dir];
			ey = ey + dy[new_dir];
			visited[ex][ey] = true;
			dir.push_back(new_dir);
		}
	}
}

int cnt = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		make_dragon(x, y, d, g);
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
				cnt++;
		}
	}
	cout << cnt;
}

