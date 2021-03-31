#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>

using namespace std;
// 36분 시작

int n, k, l;
// 1부터 시작 
int arr[101][101] = { 0, };
// 오하좌상 (+1 : D, +3: L)
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dir = 0;

// 시간, 방향 저장
queue<pair<int, char>>q;
deque<pair<int, int>>snake;
int x, y;
bool IsRange(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n)
		return true;
	return false;
}
bool Duplicate(int x, int y) {
	for (auto &k : snake) {
		if (k.first == x && k.second == y)
			return true;
	}
	return false;
}
int res = 0;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	x = 1, y = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		arr[x][y] = 1;
	}
	cin >> l;
	while (l--) {
		int time;
		char dir;
		cin >> time >> dir;
		q.push({ time,dir });
	}
	
	// 벽 또는 자기 자신과 부딪히면 게임 끝 (머리 사용 -> 큐)
	
	snake.push_front({ x,y });
	while (1) {
		res++;
		int x = snake.front().first;
		int y = snake.front().second;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!IsRange(nx, ny) || Duplicate(nx,ny))
			break;

		snake.push_front({ nx,ny });
		if (arr[nx][ny] == 1) {
			arr[nx][ny] = 0;
		}
		else {
			snake.pop_back();
		}

		// queue 항상 확인 , n 초 끝나고 방향 바뀜
		if (!q.empty() && q.front().first == res) {
			int new_dir = q.front().second;
			if (new_dir == 'L') {
				dir = (dir + 3) % 4;
			}
			else {
				dir = (dir + 1) % 4;
			}
			q.pop();
		}

	}
	cout << res;
}

