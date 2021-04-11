#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>

using namespace std;
// 13분
// n번 최대 ,, 백트레킹으로 모두 해야한다.
int t;
int n, w, h;
int total_cnt = 0;
int max_cnt;
int arr[16][16];
int res = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < h && y >= 0 && y < w)
		return true;
	return false;
}

void print_arr() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void down_arr() {
	for (int i = h - 1; i >= 0; i--) {
		for (int j = 0; j < w; j++) {
			if (i == h - 1 || arr[i][j]==0)
				continue;
			int nx = i, ny = j;
			int tmp = arr[i][j];
			arr[i][j] = 0;
			while (1) {
				if (nx == h - 1 || arr[nx + 1][ny] != 0)
					break;
				nx++;
			}
			arr[nx][ny] = tmp;
		}
	}

}

void bomb(int idx) {
	//cout << idx << endl;
	int x, y;
	x = -1;
	y = idx;
	for (int i = 0; i < h; i++) {
		if (arr[i][idx] != 0) {
			x = i;
			break;
		}
	}

	if (x == -1)
		return;

	//cout << x <<  ' '  << y << endl;

	// x y 좌표가 터진다.
	bool visited[16][16] = { false, };
	visited[x][y] = true;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int range = arr[x][y];
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < range; j++) {
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;
				if (IsRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	// 지우기
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (visited[i][j])
				arr[i][j] = 0;
		}
	}
	//cout << "터트리고 지우기 \n";
	//print_arr();
	// 내리기 
	down_arr();
	//cout << "내리기 \n";
	//print_arr();
}

void dfs(int cnt) {
	if (cnt == n) {
		int total = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] != 0)
					total++;
			}
		}
		//cout << "결과 ";
		//cout << total << endl;
		// 남아있는 칸이 적어야한다.
		res = min(res, total);
		return;
	}
	// 터트리기
	for (int i = 0; i < w; i++) {
		int tmp[16][16];
		for (int j = 0; j < h; j++) {
			for (int l = 0; l < w; l++) {
				tmp[j][l] = arr[j][l];
			}
		}
		bomb(i);
		dfs(cnt + 1);
		for (int j = 0; j < h; j++) {
			for (int l = 0; l < w; l++) {
				arr[j][l] = tmp[j][l];
			}
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int test=1; test <= t; test++) {
		res = 0;
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 0)
					res++;
			}
		}
		dfs(0);
		cout << "#" << test << ' ' << res << "\n";
	}

}