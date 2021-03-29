#include <bits/stdc++.h>
using namespace std;
struct dusk {
	int x, y, value;
};
//그대로 구현
queue<dusk> duskQ;
int arr[51][51], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int R, C,R2,C2;
//먼지 담고
void pushDusk() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 4) {
				duskQ.push({ i,j,arr[i][j] });
			}
		}
	}
}
//먼지 확산
void spread(dusk d) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = d.x + dx[i], ny = d.y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C)continue;
		if (arr[nx][ny] != -1) {
			cnt++;
			arr[nx][ny] += d.value / 5;
		}
	}
	arr[d.x][d.y] -= cnt * (d.value / 5);
}
void shiftDownToCleaner(int x) {
	x--;
	while (x > 0) {
		arr[x][0] = arr[x - 1][0];
		x--;
	}
}
void shiftDownToBottom(int x) {
	int x2 = R2;
	while (x2 > x) {
		arr[x2][C2] = arr[x2 - 1][C2];
		x2--;
	}
}
void shiftUpToCleaner(int x) {
	x++;
	while (x < R2) {
		arr[x][0] = arr[x + 1][0];
		x++;
	}
}
void shiftUpToTop(int x) {
	int x2 = 0;
	while (x2 < x) {
		arr[x2][C2] = arr[x2 + 1][C2];
		x2++;
	}
}
void shiftRight(int x) {
	int y = C - 1;
	while (y>1) {
		arr[x][y] = arr[x][y - 1];
		y--;
	}
	arr[x][y] = 0;
}
void shiftLeft(int x) {
	int y = 0;
	while (y < C2) {
		arr[x][y] = arr[x][y + 1];
		y++;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> R >> C >> T;
	R2 = R - 1;
	C2 = C - 1;
	int x1=-1,x2=-1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (x1 == -1)x1 = i;
				else x2 = i;
			}
		}
	}
	while (T--) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (arr[i][j] > 4) {
					duskQ.push({ i,j,arr[i][j] });
				}
			}
		}
		while (!duskQ.empty()) {
			spread(duskQ.front());
			duskQ.pop();
		}
		shiftDownToCleaner(x1);
		shiftLeft(0);
		shiftUpToTop(x1);
		shiftRight(x1);
		shiftUpToCleaner(x2);
		shiftLeft(R2);
		shiftDownToBottom(x2);
		shiftRight(x2);
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > 0)ans += arr[i][j];
		}
	}
	cout << ans;
}