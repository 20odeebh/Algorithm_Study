#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>
#include <stack>

using namespace std;
// 1시간 소요 ㅜ 

// 구현
// 1.미세먼지 확산 - 동시 발생이니까 queue에 모두 넣어서 진행
// 2.공기청정기 작동 - 미세먼지 이동 및 삭제

vector<pair<int, int>> machine;
int n, m, t;
int arr[51][51];
// 좌 상 우 하

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

bool IsMachine(int x, int y) {
	for (auto &k : machine) {
		if (x == k.first && y == k.second)
			return true;
	}
	return false;
}

void print_arr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void spread() {
	queue<pair<int,pair<int, int>>>q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == -1 || arr[i][j] == 0)
				continue;
			q.push({ arr[i][j], { i,j } });
			arr[i][j] = 0;
		}
	}

	while (!q.empty()) {
		int val = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		int spread_val = val / 5;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx, ny) && !IsMachine(nx,ny)) {
				arr[nx][ny] += spread_val;
				cnt++;
			}
		}
		arr[x][y] += val - (cnt*spread_val);
	}
	return;
}

void move_machine_up() {
	// 위의 공기청정기 

	int mx, my;
	mx = machine[0].first, my = machine[0].second;
	// 상 우 하 좌
	// 하 좌 상 우
	int dir = 1;
	int nx = mx + dx[dir], ny = my + dy[dir];
	while (!(nx == mx && ny == my)) {
		if (!(nx+dx[dir]>=0 && nx+dx[dir]<=mx && ny+dy[dir]>=0 && ny+dy[dir]<m)) {
			dir = (dir + 1) % 4;
		}
		arr[nx][ny] = arr[nx + dx[dir]][ny + dy[dir]];
		nx += dx[dir];
		ny += dy[dir];
	}
	return;
}

void move_machine_down() {
	// 위의 공기청정기 

	int mx, my;
	mx = machine[1].first, my = machine[1].second;
	int dir = 3;
	int nx = mx + dx[dir], ny = my + dy[dir];
	while (!(nx == mx && ny == my)) {
		if (!(nx + dx[dir] >= mx && nx + dx[dir] < n && ny + dy[dir] >= 0 && ny + dy[dir]<m)) {
			dir = (dir + 3) % 4;
		}
		arr[nx][ny] = arr[nx + dx[dir]][ny + dy[dir]];
		nx += dx[dir];
		ny += dy[dir];
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				machine.push_back({ i,j });
				arr[i][j] = 0;
			}
		}
	}

	while (t--) {
		spread();
		move_machine_up();
		move_machine_down();
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			res += arr[i][j];
	}
	cout << res;
}

