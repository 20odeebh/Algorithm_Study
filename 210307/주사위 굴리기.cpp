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
// 주사위의 위치를 인덱스로 고정하고 
// 각 값을 변경하는게 더 빠름 
int n, m, x, y, k;
int dice[6] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

int arr[21][21];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	while (k--) {
		int dir; cin >> dir;
		int nx = x + dx[dir-1];
		int ny = y + dy[dir-1];
		if (!IsRange(nx, ny))
			continue;
		int tmp[6];
		for (int i = 0; i < 6; i++)
			tmp[i] = dice[i];
		// 위 상하좌우 아래
		if (dir == 1) {
			// 동쪽으로 이동
			// 값을 변경해야하기 때문에 복사본 하나 만드는 것이 좋다.
			tmp[0] = dice[3];
			tmp[4] = dice[0];
			tmp[5] = dice[4];
			tmp[3] = dice[5];
		}
		else if (dir == 2) {
			// 서쪽으로 이동
			tmp[0] = dice[4];
			tmp[3] = dice[0];
			tmp[5] = dice[3];
			tmp[4] = dice[5];
		}
		else if (dir == 3) {
			// 북쪽
			tmp[0] = dice[2];
			tmp[1] = dice[0];
			tmp[5] = dice[1];
			tmp[2] = dice[5];
		}
		else {
			// 남쪽
			tmp[0] = dice[1];
			tmp[2] = dice[0];
			tmp[5] = dice[2];
			tmp[1] = dice[5];
		}
		// tmp에 복사
		if (arr[nx][ny] == 0) {
			arr[nx][ny] = tmp[5];
		}
		else {
			tmp[5] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		cout << tmp[0] << '\n';
		for (int i = 0; i < 6; i++)
			dice[i] = tmp[i];
		x = nx, y = ny;
	}

}