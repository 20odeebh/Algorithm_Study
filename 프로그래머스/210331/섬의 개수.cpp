#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[51][51], dx[8] = {-1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,1,-1,-1,0,1 };
bool check[51][51];
int n, m;
//8방향 탐색 dfs
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (arr[nx][ny] && check[nx][ny] == false) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				check[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && check[i][j] == false) {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}
}