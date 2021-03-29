#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m,res=-1;
int a[8][8], dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
struct wall {
	int y, x;
};
vector<wall> v;

int bfs() {
	queue<pair<int, int>> q;
	int visit[8][8] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2 && visit[i][j] == 0) {
				q.push({ i,j });
				visit[i][j] = 1;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
						if (a[ny][nx] == 1 || visit[ny][nx])continue;
						q.push({ ny,nx });
						visit[ny][nx] = visit[y][x] + 1;
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && visit[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void dfs(int cur, int cnt) {
	if (cnt == 3) {
		int candi=bfs();
		if (res < candi)res = candi;
		return;
	}
	for (int i = cur; i < v.size(); i++) {
		a[v[i].y][v[i].x] = 1;
		dfs(i + 1, cnt + 1);
		a[v[i].y][v[i].x] = 0;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << res;
}
