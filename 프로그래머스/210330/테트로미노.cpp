#include <iostream>
using namespace std;
int a[501][501];
int n, m;
int ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool c[501][501];
//못풀어서 옛날 제출한 소스 참고
//dfs와 백트래킹으로 하면서, count가 가질 수 있는 값에 따라 상하좌우 이동 경우의 수를 모두 체크해준다.
void dfs(int x, int y, int count, int sum) {
	c[x][y] = true;
	if (count == 4) {
		sum += a[x][y];
		if (ans < sum)ans = sum;
		c[x][y] = false;
		return;
	}
	else {
		sum += a[x][y];
		if (count == 2) {
			int temp = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx > -1 && nx<n && ny>-1 && ny < m) {
					if (c[nx][ny]) {
						temp = i;
						break;
					}
				}
			}
			if (temp == 0) {
				if (x == 0) {
					if (y) {
						sum += (a[x][y - 1] + a[x + 1][y]);
						if (ans < sum)ans = sum;
						sum -= (a[x][y - 1] + a[x + 1][y]);
					}
				}
				if (x > 0 && x < n - 1) {
					sum += (a[x - 1][y] + a[x + 1][y]);
					if (ans < sum)ans = sum;
					sum -= (a[x - 1][y] + a[x + 1][y]);
				}
				if (x == n - 1) {
					if (y) {
						sum += (a[x][y - 1] + a[x - 1][y]);
						if (ans < sum)ans = sum;
						sum -= (a[x][y - 1] + a[x - 1][y]);
					}
				}
			}
			else if (temp == 1) {
				if (x == 0) {
					if (y < m - 1) {
						sum += (a[x][y + 1] + a[x + 1][y]);
						if (ans < sum)ans = sum;
						sum -= (a[x][y + 1] + a[x + 1][y]);
					}
				}
				if (x > 0 && x < n - 1) {
					sum += (a[x - 1][y] + a[x + 1][y]);
					if (ans < sum)ans = sum;
					sum -= (a[x - 1][y] + a[x + 1][y]);
				}
				if (x == n - 1) {
					if (y < m - 1) {
						sum += (a[x][y + 1] + a[x - 1][y]);
						if (ans < sum)ans = sum;
						sum -= (a[x][y + 1] + a[x - 1][y]);
					}
				}
			}
			else if (temp == 2) {
				if (y == 0) {
					if (x) {
						sum += (a[x - 1][y] + a[x][y + 1]);
						if (ans < sum)ans = sum;
						sum -= (a[x - 1][y] + a[x][y + 1]);
					}
				}
				if (y > 0 && y < m - 1) {
					sum += (a[x][y - 1] + a[x][y + 1]);
					if (ans < sum)ans = sum;
					sum -= (a[x][y - 1] + a[x][y + 1]);
				}
				if (y == m - 1) {
					if (x) {
						sum += (a[x - 1][y] + a[x][y - 1]);
						if (ans < sum)ans = sum;
						sum -= (a[x - 1][y] + a[x][y - 1]);
					}
				}
			}
			else {
				if (y == 0) {
					if (x < n - 1) {
						ans += (a[x + 1][y] + a[x][y + 1]);
						if (ans < sum)ans = sum;
						ans -= (a[x + 1][y] + a[x][y + 1]);
					}
				}
				if (y > 0 && y < m - 1) {
					sum += (a[x][y - 1] + a[x][y + 1]);
					if (ans < sum)ans = sum;
					sum -= (a[x][y - 1] + a[x][y + 1]);
				}
				if (y == m - 1) {
					if (x < n - 1) {
						sum += (a[x + 1][y] + a[x][y - 1]);
						if (ans < sum)ans = sum;
						sum -= (a[x + 1][y] + a[x][y - 1]);
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx > -1 && nx<n && ny>-1 && ny < m) {
				if (!c[nx][ny]) {
					dfs(nx, ny, count + 1, sum);
				}
			}
		}
		c[x][y] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, 1, 0);
		}
	}
	cout << ans;
}