#include <iostream>
#include <string>
#include<cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include<functional>
#include <climits>
#include <stack>

using namespace std;
// 48분
int n;
int arr[21][21];
int numbering[21][21];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int X, Y, D1, D2;
int res = INT_MAX;
int total = 0;
vector<pair<int, int>>v[201];

bool IsRange(int x, int y) {
	if (x > 0 && x <= n && y > 0 && y <= n)
		return true;
	return false;
}

bool canXGo(int x, int d1, int d2) {
	int border = x + d1 + d2;
	if (x >= 1 && x < border && border<= n)
		return true;
	return false;
}

bool canYGo(int y, int d1, int d2) {
	int sy = y - d1;
	int ey = y + d2;
	if (sy >= 1 && y > sy && y < ey && ey <= n)
		return true;
	return false;
}

int number(int x, int y) {
	if (x >= 1 && x < X + D1 && y >= 1 && y <= Y)
		return 1;
	else if (x >= 1 && x<= X + D2 && y>Y && y <= n)
		return 2;
	else if (x >= X + D1 && x <=n && y >= 1 && y < Y - D1 + D2)
		return 3;
	else
		return 4;
}

void bfs() {

	int people[6] = { 0, };
	queue<pair<int, int>>q;
	bool visited[21][21] = { false, };
	q.push({ 1,1 });
	visited[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		// 몇번 선거구를 돌았는지 확인하기 위해
		int num = number(x, y);
		people[num] += arr[x][y];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (IsRange(nx,ny) && !visited[nx][ny] && numbering[nx][ny] == 0) {
				// 5는 들어올 수 없기 때문 외부의 값들에 대해 bfs
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	int tmp = 0;
	for (int i = 1; i <= 4; i++)
		tmp += people[i];

	people[5] = total - tmp;

	sort(people, people + 6);
	// 차의 최솟값
	res = min(res, people[5] - people[1]);
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j]; 
			total += arr[i][j];
		}
	}
	// 기준점 구하기 
	for (int d1 = 1; d1 < n; d1++) {
		for (int d2 = 1; d2 < n; d2++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= n; y++) {
					if (!canYGo(y, d1, d2) || !canXGo(x,d1,d2))
						continue;

					X = x, Y = y, D1 = d1, D2 = d2;
					// 5번 선거구의 경계선 만들기
					memset(numbering, 0, sizeof(numbering));
					// 네 방향으로 진행
					int nx1 = x + d1; int ny1 = y - d1;
					int nx2 = x + d2; int ny2 = y + d2;
					int nx3 = x + d2 + d1; int ny3 = y + d2 - d1;
					int sx = x; int sy = y;
					numbering[sx][sy] = 5;

					while (!(sx == nx1 && sy == ny1)) {
						sx += 1, sy -= 1;
						numbering[sx][sy] = 5;
					}
					sx = x; sy = y;
					while (!(sx == nx2 && sy == ny2)) {
						sx += 1, sy += 1;
						numbering[sx][sy] = 5;
					}
					while (!(nx1 == nx3 && ny1 == ny3)) {
						nx1 += 1, ny1 += 1;
						numbering[nx1][ny1] = 5;
					}
					while (!(nx2 == nx3 && ny2 == ny3)) {
						nx2 += 1, ny2 -= 1;
						numbering[nx2][ny2] = 5;
					}
					bfs();
				}
			}
		}
	}
	cout << res;

}