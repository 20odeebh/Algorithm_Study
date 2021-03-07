#include <iostream>
using namespace std;
int a[20][20];
int dice[7];
int d[5];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
//500원 입금했습니다
//3일동안 4시간 잤더니 도저히 생각이 안됨..
//자고일어나서 블록이동하기 풀고 주사위 굴리기 리뷰
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, x, y, T;
	cin >> n >> m >> x >> y >> T;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	d[0] = 1; d[1] = 3; d[2] = 4; d[3] = 2; d[4] = 5;
	int t;
	for (int i = 0; i < T; i++) {
		cin >> t;
		int nx = x + dx[t], ny = y + dy[t];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;;
		x = nx; y = ny;
		int p = d[0];
		if (t < 3) {
			if (t == 1) {
				d[0] = d[1];
				d[2] = p;
				d[1] = 7 - d[2];
			}
			else {
				d[1] = p;
				d[0] = d[2];
				d[2] = 7 - d[1];
			}
		}
		else {
			if (t == 3) {
				d[0] = d[3];
				d[4] = p;
				d[3] = 7 - d[4];

			}
			else {
				d[0] = d[4];
				d[3] = p;
				d[4] = 7 - d[3];
			}
		}
		if (a[x][y]) {
			dice[d[0]] = a[x][y];
			a[x][y] = 0;
		}
		else {
			a[x][y] = dice[d[0]];
		}
		cout << dice[7 - d[0]] << '\n';
	}
}