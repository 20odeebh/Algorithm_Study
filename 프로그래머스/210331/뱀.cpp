#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
deque<pair<int, int>> dq;
//큐로 구현
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
	int l;
	cin >> l;
	int time = 0, dir = 1;
	a[1][1] = 2;
	dq.push_front({ 1,1 });
	while (l >= 0) {
		int x; char c;
		if (l == 0) {
			x = 1000; c = 'D';
		}
		else {
			cin >> x >> c;
		}
		while (time < x) {
			time++;
			int nx = dq.front().first + dx[dir], ny = dq.front().second + dy[dir];
			if (nx<1 || nx>n || ny<1 || ny>n) {
				cout << time;
				return 0;
			}
			if (a[nx][ny] == 2) {
				cout << time;
				return 0;
			}
			if (a[nx][ny] == 0) {
				a[dq.back().first][dq.back().second] = 0;
				dq.pop_back();
			}
			a[nx][ny] = 2;
			dq.push_front({ nx, ny });
		}
		if (c == 'D')dir++;
		else dir--;
		if (dir < 0)dir += 4;
		if (dir > 3)dir -= 4;
		l--;
	}
}