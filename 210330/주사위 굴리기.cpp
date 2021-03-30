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

using namespace std;
int dice[6] = { 0, };
int n, m, x, y, k;
int arr[21][21];
// 동 서 북 남 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n &&y >= 0 && y < m)
		return true;
	return false;
}

void move_dice(int dir) {
	// 동쪽 이동
	if (dir == 0) {
		int tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == 1) {
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
		
	}
	else if (dir == 2) {
		int tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	else {
		int tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	// 동서북남
	while (k--) {
		int dir; cin >> dir;
		dir--;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!IsRange(nx, ny))
			continue;
		move_dice(dir);
		if (arr[nx][ny] == 0) {
			arr[nx][ny] = dice[5];
		}
		else {
			dice[5] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		x += dx[dir];
		y += dy[dir];
		cout << dice[0] << '\n';
	}

}

