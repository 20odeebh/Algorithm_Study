#include <bits/stdc++.h>
using namespace std;
//끔찍한 구현문제
//궁수를 배치할 수 있는 모든 경우의 수에 대하여 (최대 455가지)
//시뮬레이션을 진행후 최대값 계산
int a[16][16], a2[460][16][16],n,m,d;
int dp[460];
int dx[4] = { 0,-1,1,0 }, dy[4] = { -1,0,0,1 };
bool check[16][16];
vector<pair<int, int>> v[11][16];
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
struct A {
	int x, y, dist;
};
queue<A> q;
//각 y열을 기준으로 거리 1~10까지의 좌표를 모두 v에다 넣어준다.
void bfs(int y) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			check[i][j] = false;
		}
	}
	q.push({ n + 1,y,0 });
	while (!q.empty()) {
		int x1 = q.front().x, y1 = q.front().y, dist = q.front().dist;
		q.pop();
		if (dist >= d)continue;
		for (int i = 0; i < 4; i++) {
			int nx = x1 + dx[i], ny = y1 + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>m)continue;
			if (check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push({ nx,ny,dist + 1 });
				v[dist + 1][y].push_back({ nx,ny });
			}
		}
	}
}
pair<int, int> findPos(int num,int y) {
	for (int i = 1; i <= d; i++) {
		for (auto k : v[i][y]) {
			if (a2[num][k.first][k.second] == 1) {
				return { k.first,k.second };
			}
		}
	}
	return { n,y };
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> d;
	int temp = (m * (m - 1) * (m - 2)) / 6;
	for (int i = 1; i <= m; i++) {
		bfs(i);
	}
	// 각 j열에 대해서 거리에대한 좌표를 y순으로 정렬
	// 가장 왼쪽부터 가까운것을 찾기 위해
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= m; j++) {
			sort(v[i][j].begin(), v[i][j].end(),cmp);
		}
	}
	//입력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			for (int k = 0; k < temp; k++) {
				a2[k][i][j] = a[i][j];
			}
		}
	}
	int n2 = n;
	int first = m - 2, second = m - 1;
	while (n2) {
		int cnt = 0;
		for (int i = 1; i <= first; i++) {
			for (int j = i + 1; j <= second; j++) {
				for (int k = j + 1; k <= m; k++) {
					pair<int, int> pos1 = findPos(cnt,i);
					pair<int, int> pos2 = findPos(cnt,j);
					pair<int, int> pos3 = findPos(cnt,k);
					if (a2[cnt][pos1.first][pos1.second]) {
						dp[cnt]++;
						a2[cnt][pos1.first][pos1.second] = 0;
					}
					if (a2[cnt][pos2.first][pos2.second]) {
						dp[cnt]++;
						a2[cnt][pos2.first][pos2.second] = 0;
					}
					if (a2[cnt][pos3.first][pos3.second]) {
						dp[cnt]++;
						a2[cnt][pos3.first][pos3.second] = 0;
					}
					cnt++;
				}
			}
		}
		//각 a2 배열에 대해서 한 라인씩 내려주는 작업
		for (int i = 0; i < temp; i++) {
			for (int j = n - 1; j > 0; j--) {
				for (int k = 1; k <= m; k++) {
					a2[i][j + 1][k] = a2[i][j][k];
				}
			}
		}
		for (int i = 0; i < temp; i++) {
			for (int j = 1; j <= m; j++) {
				a2[i][1][j] = 0;
			}
		}
		n2--;
	}
	int ans = 0;
	for (int i = 0; i < temp; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}