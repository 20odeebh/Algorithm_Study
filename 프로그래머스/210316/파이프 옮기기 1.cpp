#include <bits/stdc++.h>
using namespace std;
int a[17][17];
int n;
bool check[17][17][3];
int d[17][17][3];
//다이나믹 프로그래밍
//d[i][j] = i행 j열에서 시작했을때 n행n열까지 가는 경우의수

bool checkLow(int x, int y) {
	if (x + 1 <= n) {
		if (a[x + 1][y] == 0)return true;
	}
	return false;
}
bool checkRight(int x, int y) {
	if (y + 1 <= n) {
		if (a[x][y + 1] == 0)return true;
	}
	return false;
}
bool checkDia(int x, int y) {
	bool ret = true;
	if (x + 1 <= n) {
		if (a[x + 1][y] == 1)ret = false;
	}
	else return false;
	if (y + 1 <= n) {
		if (a[x][y + 1] == 1)ret = false;
	}
	else return false;
	if (a[x + 1][y + 1] == 1)ret = false;
	return ret;
}
int go(int x, int y, int dir) {
	if (check[x][y][dir])return d[x][y][dir];
	check[x][y][dir] = true;
	if (checkDia(x, y)) {
		d[x][y][dir]+=go(x + 1, y + 1, 2);
	}
	if (dir == 0 || dir==2) {
		if (checkRight(x, y)) {
			d[x][y][dir]+=go(x, y + 1, 0);
		}
	}
	if (dir == 1 || dir == 2) {
		if(checkLow(x,y)){
			d[x][y][dir]+=go(x + 1, y, 1);
		}
	}
	return d[x][y][dir];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		check[n][n][i] = true;
		d[n][n][i] = 1;
	}
	cout<<go(1, 2, 0);
}