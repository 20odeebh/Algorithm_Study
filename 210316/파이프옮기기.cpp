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

using namespace std;
// 54분 // 52분...
int n;
int arr[20][20];
vector<pair<int, int>> pipe(2);
int res = 0;

// 두개의 파이프가 이동해야하는 방향
// 가로 세로 대각선

int dx[3] = { 1,1,0 };
int dy[3] = { 0,1,1 };

bool go(int dir) {
	// 가로
	if (dir == 1) {
		if (pipe[1].second + 1 <= n && arr[pipe[1].first][pipe[1].second + 1] == 0)
			return true;
		return false;
	}
	// 세로
	else if (dir == 2) {
		if (pipe[1].first + 1 <= n && arr[pipe[1].first + 1][pipe[1].second] == 0)
			return true;
		return false;
	}
	// 대각선
	else {
		int x = pipe[1].first;
		int y = pipe[1].second;
		// 세 방향에 대해서 범위 안에 없거나 벽이 있으면 false
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				return false;
			if (arr[nx][ny] == 1)
				return false;
		}
		return true;
	}
}

void change(int dir) {
	int x2 = pipe[1].first;
	int y2 = pipe[1].second;

	pipe[0].first = x2;
	pipe[0].second = y2;
	
	// 가로
	if (dir == 1) {
		pipe[1].second = y2 + 1;
	}
	// 세로
	else if (dir == 2) {
		pipe[1].first = x2 + 1;
	}
	// 대각선
	else {
		pipe[1].first++;
		pipe[1].second++;
	}

}


int check_pipe() {
	int x1 = pipe[0].first;
	int y1 = pipe[0].second;
	int x2 = pipe[1].first;
	int y2 = pipe[1].second;
	// 가로
	if (x1 == x2)
		return 1;
	// 세로
	else if (y1 == y2)
		return 2;
	// 대각선
	else
		return 3;
}

void dfs() {
	// 마지막에 도착했으면 return;
	if (pipe[1].first == n  && pipe[1].second == n ) {
		res++;
		return;
	}

	// 파이프 형태 검사 
	int dir = check_pipe();
	// tmp 저장
	vector<pair<int, int>> tmp(pipe.begin(), pipe.end());
	if (dir == 1) {
		for (int k = 1; k <= 3; k++) {
			if (k == 2)
				continue;
			if (go(k)) {
				change(k);
				dfs();
				pipe = tmp;
			}
		}
	}
	else if (dir == 2) {
		for (int k = 1; k <= 3; k++) {
			if (k == 1)
				continue;
			if (go(k)) {
				change(k);
				dfs();
				pipe = tmp;
			}
		}
	}
	else {
		for (int k = 1; k <= 3; k++) {
			if (go(k)) {
				change(k);
				dfs();
				pipe = tmp;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	pipe[0] = { 1,1 };
	pipe[1] = { 1,2 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}


	dfs();

	cout << res;
}