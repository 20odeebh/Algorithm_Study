#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cnt,ret,n,shark_y,shark_x,sharkSize=2;
int a[50][50];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
struct FISH {
	int y, x, d;
	bool operator< (FISH& a)const{
		if (d == a.d) {
			if (y == a.y) {
				return x < a.x;
			}
			return y < a.y;
		}
		return d < a.d;
	}
};



int bfs(int fy, int fx) {
	
	
	queue<pair<int, int>> q;
	int vis[50][50] = { 0 };
	
	q.push(make_pair(shark_y, shark_x));
	vis[shark_y][shark_x] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
			if (a[ny][nx] > sharkSize || vis[ny][nx] != 0)continue;
			vis[ny][nx] = vis[y][x] + 1;
			q.push(make_pair(ny, nx));
			if (ny == fy && nx == fx)return vis[ny][nx] - 1;
		}
	}
	return 0;
}
void solve() {	
	vector<FISH> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < sharkSize && a[i][j] != 0) {
				int d = bfs(i, j);
				if(d) v.push_back({ i,j,d });
			}
		}
	}
	if (v.size()) {
		sort(v.begin(), v.end());
		ret += v[0].d;
		a[shark_y][shark_x] = 0;
		shark_y = v[0].y;
		shark_x = v[0].x;
		if (++cnt==sharkSize) {
			cnt = 0;
			sharkSize += 1;

		}
		solve();
	}
}
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				shark_y = i;
				shark_x = j;
			}
		}
	}
	solve();
	cout << ret;

}
