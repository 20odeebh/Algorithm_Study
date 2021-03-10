#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_map>

using namespace std;
// 40분
// 북동남서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int arr[51][51] = { 0, };
int r, c, d;
int cnt = 0;
bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	// 시작점 청소
	arr[r][c] = 2;
	cnt += 1;

	while (1) {
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			// 현재의 왼쪽방향부터 탐색
			int nd = (d + 3) % 4;
			int nx = r + dx[nd];
			int ny = c + dy[nd];
			// 청소하지 않은 공간이 존재한다면
			if (arr[nx][ny] == 0) {
				// 청소
				arr[nx][ny] = 2;
				cnt += 1;
				// 방향 회전
				d = nd;
				// 칸 전진
				r = nx, c = ny;
				flag = true;
				break;
			}
			// 청소할 공간이 없으면 회전 후 다시 시작
			else {
				d = nd;
			}
		}
		if (flag)
			continue;

		// 네 방향 모두 청소할 곳이 존재하지 않는다면
		// 되돌아가기
		int bx = r + dx[(d + 2) % 4];
		int by = c + dy[(d + 2) % 4];
		if (arr[bx][by] == 1 || !IsRange(bx, by)) {
			break;
		}
		else {
			r = bx, c = by;
		}
	}
	cout << cnt;
}