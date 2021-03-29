#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int a[8][8];
int b[8][8];
int n, m, viruscount;
queue<pair<int, int>> q;
pair<int, int> virus[81];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	for (int i = 0; i < viruscount; i++) {
		q.push({ virus[i].first,virus[i].second });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (!a[nx][ny]) {
					a[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int nm = n * m;
	int nm1 = nm - 2;
	int nm2 = nm - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				virus[viruscount].first = i;
				virus[viruscount++].second = j;
			}
		}
	}
	int ans = 0, count = 0;
	//모든 3개를 벽을 칠 수 있는 경우의 수에 대하여 완전탐색
	//이때 i행 j열은 계산식 나누기와 나머지 연산자로 구분가능
	for (int i = 0; i < nm1; i++) {
		if (!a[i / m][i % m]) {
			a[i / m][i % m] = 1;
			for (int j = i + 1; j < nm2; j++) {
				if (!a[j / m][j % m]) {
					a[j / m][j % m] = 1;
					for (int k = j + 1; k < nm; k++) {
						if (!a[k / m][k % m]) {
							a[k / m][k % m] = 1;
							bfs();
							count = 0;
							for (int i1 = 0; i1 < n; i1++) {
								for (int j1 = 0; j1 < m; j1++) {
									if (!a[i1][j1])count++;
									if (a[i1][j1] == 2) {
										a[i1][j1] = 0;
									}
								}
							}

							if (count > ans)ans = count;
							for (int i1 = 0; i1 < viruscount; i1++) {
								a[virus[i1].first][virus[i1].second] = 2;
							}
							a[k / m][k % m] = 0;
						}
					}
					a[j / m][j % m] = 0;
				}
			}
			a[i / m][i % m] = 0;
		}
	}
	cout << ans;
}