#include <bits/stdc++.h>
using namespace std;
int a[51][51];
//그룹, 국가의 수, 인구수
int p[2600], psum[2600], pasum[2600], toNum[51][51];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

int Find(int x) {
	if (p[x] == x)return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[y] = x;
	psum[x] += psum[y];
	pasum[x] += pasum[y];
}
int dif(int x, int y, int nx, int ny) {
	return abs(a[x][y] - a[nx][ny]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			toNum[i][j] = i * n + j;
		}
	}
	int ans = 0;
	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				p[toNum[i][j]] = toNum[i][j];
				psum[toNum[i][j]] = 1;
				pasum[toNum[i][j]] = a[i][j];
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					int diff = dif(i, j, nx, ny);
					if (diff >= l && diff <= r) {
						if (Find(toNum[i][j]) != Find(toNum[nx][ny])) {
							flag = true;
							Union(toNum[i][j], toNum[nx][ny]);
						}
					}
				}
			}
		}
		if (flag == false) {
			cout << ans << '\n';
			return 0;
		}
		ans++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = Find(toNum[i][j]);
				a[i][j] = pasum[x] / psum[x];
			}
		}
	}
}