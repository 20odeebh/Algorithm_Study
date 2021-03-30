#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>
// 브루트포스 계속 실패, 구글링해서 dfs의 depth가 4라는 특징 있음
// 대신 ㅗ ㅜ ㅏ ㅓ는 따로 계산해야함
using namespace std;
int n, m;
int arr[501][501];
bool visited[501][501] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int res = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

void dfs(int x, int y, int depth, int total) {
	if (depth == 4) {
		res = max(res, total);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (IsRange(nx, ny) && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, depth + 1, total + arr[nx][ny]);
			visited[nx][ny] = false;
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j, 1, arr[i][j]);
				visited[i][j] = false;
			}
		}
	}

	// ㅗ ㅜ ㅓ ㅏ 모양은 따로 탐색 필요
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// i,j에서 시작 각각 모양 살펴보기
			if (IsRange(i, j) && IsRange(i, j + 1) && IsRange(i, j + 2) && IsRange(i + 1, j + 1)) {
				res = max(res, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
			}
			if (IsRange(i, j) && IsRange(i, j + 1) && IsRange(i, j + 2) && IsRange(i - 1, j + 1)) {
				res = max(res, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1]);
			}
			if (IsRange(i, j) && IsRange(i, j+1) && IsRange(i - 1, j + 1) && IsRange(i + 1, j + 1)) {
				res = max(res, arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i + 1][j + 1]);
			}
			if (IsRange(i, j) && IsRange(i, j + 1) && IsRange(i-1, j) && IsRange(i + 1, j)) {
				res = max(res, arr[i][j] + arr[i][j + 1] + arr[i - 1][j] + arr[i + 1][j]);
			}
		}
	}
	cout << res;

}

