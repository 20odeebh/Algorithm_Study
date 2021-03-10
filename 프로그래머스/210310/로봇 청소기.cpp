#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m,ans=0;
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (true) {
		int ndir = dir;
		bool flag = false;
		a[x][y] = 2;
		for (int i = 0; i < 4; i++) {
			ndir--;
			if (ndir < 0)ndir += 4;
			int nx = x + dx[ndir], ny = y + dy[ndir];
			if (a[nx][ny] == 0) {
				x = nx; y = ny;
				dir = ndir;
				flag = true;
				break;
			}
		}
		//한쪽 방향이라도 청소할 공간이 있다면
		if (flag) {
			continue;
		}
		if (a[x + dx[(dir + 2) % 4]][y + dy[(dir + 2) % 4]] == 1) {
			break;
		}
		x += dx[(dir + 2) % 4];
		y += dy[(dir + 2) % 4];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2)ans++;
		}
	}
	cout << ans << '\n';
}