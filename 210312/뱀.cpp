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
#include <unordered_map>

using namespace std;

int n, k;
int arr[101][101];
// 우상좌하
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int dir = 0;
deque<pair<int, int>>dq;
int total = 0;
// 뱀의 머리와 꼬리를 처리해야하기 때문에 처음과 끝 처리가 가능한 dq사용

// 끝나는 조건: 뱀이 벽이나 자기자신의 몸과 부딪힐 때
bool IsRange(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n)
		return true;
	return false;
}
bool IsDup(int x, int y) {
	for (auto &k : dq) {
		if (x == k.first && y == k.second)
			return true;
	}
	return false;
}

int main() {
	cin >> n >> k;
	while (k--) {
		int x, y; cin >> x >> y;
		arr[x][y] = 1;
	}
	int l; cin >> l;
	queue<pair<int, char>> q;
	while (l--) {
		int time;
		char dir;
		cin >> time >> dir;
		q.push({ time,dir });
	}
	// 처음 뱀의 위치
	dq.push_back({ 1,1 });

	while (1) {
		total++;
		int nx = dq.front().first + dx[dir];
		int ny = dq.front().second + dy[dir];
		// 종료 조건
		if (!IsRange(nx, ny) || IsDup(nx, ny)) {
			break;
		}
		// 머리 추가
		dq.push_front({ nx,ny });
		if (arr[nx][ny] == 1) {
			// 사과 있을 때
			arr[nx][ny] = 0;
		}
		else {
			// 꼬리 삭제
			dq.pop_back();
		}
		// 방향이 바뀌는 시간일 때 처리
		if (!q.empty() && total == q.front().first) {
			char cur_dir = q.front().second;
			q.pop();
			// 왼쪽
			if (cur_dir == 'L') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = (dir + 3) % 4;
			}
		}
	}
	cout << total;
}

