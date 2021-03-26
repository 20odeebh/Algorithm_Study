#include <iostream>

using namespace std;

int ans,n, a[20][20], dx[] = { 0,1,1 }, dy[] = { 1,0,1 };

void go(int x, int y, int z) {
	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (z + i == 1) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || ny >= n || a[nx][ny])continue;
		if (i == 2 && (a[x + 1][y] || a[x][y + 1]))continue;
		go(nx, ny, i);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 1, 0);
	cout << ans;
}
