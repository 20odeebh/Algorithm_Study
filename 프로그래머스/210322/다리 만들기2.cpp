#include <bits/stdc++.h>
using namespace std;
int a[11][11], p[7], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool check[11][11];
int n, m;
//전체 로직은 섬마다 번호를 부여하고
//서로 다른 섬끼리 연결할 수 있는 다리와 길이를 찾아서
//크루스컬 알고리즘으로 MST를 만든다
struct A {
	int x, y, dist;
	bool operator<(const A& p)const {
		return dist < p.dist;
	}
};
A bridge[1000];
int Find(int x) {
	if (p[x] == x)return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[y] = x;
}
void dfs(int x, int y, int num) {
	check[x][y] = true;
	a[x][y] = num;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (a[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny, num);
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int islandNum = 1, bridgeNum = 0;
	for (int i = 1; i <= 6; i++)p[i] = i;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	//numbering island
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && check[i][j] == false) {
				dfs(i, j, islandNum);
				islandNum++;
			}
		}
	}
	islandNum--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					int bridgeLength = 0;
					//쭉 뻗는 다른 섬과의 연결 다리를 찾는다.
					while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (a[nx][ny] == 0) {
							bridgeLength++;
							nx = nx + dx[k]; ny = ny + dy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m)bridgeLength = 0;
						}
						else {
							if (a[nx][ny] == a[i][j])bridgeLength = 0;
							break;
						}
					}
					if (bridgeLength > 1) {
						bridge[bridgeNum].x = a[i][j];
						bridge[bridgeNum].y = a[nx][ny];
						bridge[bridgeNum].dist = bridgeLength;
						bridgeNum++;
					}
				}
			}
		}
	}
	sort(bridge, bridge + bridgeNum);
	int ans = 0;
	for (int i = 0; i < bridgeNum; i++) {
		int x = bridge[i].x, y = bridge[i].y, dist = bridge[i].dist;
		if (Find(x) != Find(y)) {
			ans += dist;
			Union(x, y);
		}
	}
	for (int i = 1; i <= islandNum; i++) {
		if (Find(1) != Find(i)) {
			cout << -1;
			return 0;
		}
	}
	cout << ans << '\n';
}