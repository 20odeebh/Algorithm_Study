#include <iostream>
#include <string>
#include<string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<functional>
#include <climits>

using namespace std;
// 32분

int r, c;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int arr[55][55];
int wx, wy;
int x, y;
int ex, ey;
bool visited[51][51] = { false, };
vector<pair<int, int>>waters;

bool IsRange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 고슴도치 이동
	// 물 이동 
	cin >> r >> c;
	// 돌 통과 x, 서로 이동 ,x
	// 고슴도치가 굴로 이동하기 위한 최소 시간
	// 다음시간에 물이 찰 것이면  고슴도치 이동 x
	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < c; j++) {
			char ch = str[j];
			int val;
			if (ch == '.')
				val = 0;
			// 물
			else if (ch == '*') {
				waters.push_back({ i,j });
				val = 1;
			}
			else if (ch == 'D') {
				ex = i, ey = j;
				val = 2;
			}
			else if (ch == 'X')
				val = 3;
			// 두더지
			else {
				val = 4;
				x = i, y = j;
			}
			arr[i][j] = val;
		}
	}

	queue < pair<int, pair<int, int>>> q1;

	for (auto &k : waters) {
		q1.push({ 0,{ k.first,k.second } });
		visited[k.first][k.second];
	}

	visited[x][y] = true;
	q1.push({ 0,{ x,y } });

	while (!q1.empty()) {
		int cx = q1.front().second.first;
		int cy = q1.front().second.second;
 		int time = q1.front().first;
		q1.pop();
		if (cx == ex && cy == ey) {
			cout << time;
			exit(0);
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			// 물
			if (arr[cx][cy] == 1) {
				if (IsRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
					visited[nx][ny] = true;
					arr[nx][ny] = 1;
					q1.push({ time + 1,{ nx,ny } });
				}
			}
			// 두더지
			else if (arr[cx][cy] == 4) {
				if (IsRange(nx, ny) && !visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == 2)) {
					visited[nx][ny] = true;
					arr[nx][ny] = 4;
					q1.push({ time + 1,{nx,ny} });
				}
			}
		}
	}
	cout << "KAKTUS";
}