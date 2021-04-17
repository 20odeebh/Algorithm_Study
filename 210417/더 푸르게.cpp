// 더 푸르게

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int w, h, ret;
char arr[11][11];
struct Point {
	int y, x;
	char ch;
};
vector<Point> v;

int dKingy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dKingx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int dQueeny[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dQueenx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int dBishopy[4] = { -1, -1, 1, 1 };
int dBishopx[4] = { -1, 1, -1, 1 };
int dRooky[4] = { 0 ,0 ,1, -1 };
int dRookx[4] = { 1, -1, 0, 0 };
int dKnighty[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dKnightx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void King(int y, int x, bool& flag) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dKingy[i];
		int nx = x + dKingx[i];
		if (ny < 0 || ny == h || nx < 0 || nx == w) continue;
		if (arr[ny][nx] != 'E') return;
	}
	flag = true;
}

void Queen(int y, int x, bool& flag) {
	for (int i = 0; i < 8; i++) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dQueeny[i];
			nx += dQueenx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return;
		}
	}
	flag = true;
}

void Bishop(int y, int x, bool& flag) {
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dBishopy[i];
			nx += dBishopx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return;
		}
	}
	flag = true;
}

void Rook(int y, int x, bool& flag) {
	for (int i = 0; i < 4; i++) {
		int ny = y;
		int nx = x;
		while (true) {
			ny += dRooky[i];
			nx += dRookx[i];
			if (ny < 0 || ny == h || nx < 0 || nx == w) break;
			if (arr[ny][nx] != 'E') return;
		}
	}
	flag = true;
}

void Knight(int y, int x, bool& flag) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dKnighty[i];
		int nx = x + dKnightx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (arr[ny][nx] != 'E') return;
	}
	flag = true;
}

bool promising() {
	for (auto& it : v) {
		if (arr[it.y][it.x] == 'E') continue;
		bool flag = false;
		switch (it.ch)
		{
		case 'K': King(it.y, it.x, flag); break;
		case 'Q': Queen(it.y, it.x, flag);  break;
		case 'B': Bishop(it.y, it.x, flag);  break;
		case 'R': Rook(it.y, it.x, flag);  break;
		case 'N': Knight(it.y, it.x, flag);  break;
		}
		if (!flag) return false;
	}
	return true;
}

void dfs(int idx, int del) {
	if (del >= ret) return;
	if (idx == v.size()) {
		if (promising()) ret = del;
		return;
	}
	dfs(idx + 1, del);
	arr[v[idx].y][v[idx].x] = 'E';
	dfs(idx + 1, del + 1);
	arr[v[idx].y][v[idx].x] = v[idx].ch;
}

int main() {
	string str;
	while (cin >> str) {
		ret = 16;
		v.clear();
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 'E') v.push_back({ i, j, arr[i][j] });
			}
		}

		dfs(0, 0);
		cout << "Minimum Number of Pieces to be removed: " << ret << '\n';
		cin >> str;
	}
	return 0;
}