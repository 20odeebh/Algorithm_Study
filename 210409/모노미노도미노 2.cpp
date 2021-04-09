#include <bits/stdc++.h>

using namespace std;

struct info {
	int y, x;
};
info tmp;

bool arr[13][13];
vector<info> v;
int dx[2] = { 0,1 }, dy[2] = { 1,0 }, result;

int calculate() {
	int cnt = 0;
	
	for (int i = 6; i < 10; i++)
		for (int j = 0; j < 4; j++)
			if (arr[i][j]) cnt++;
	
	for (int x = 6; x < 10; x++)
		for (int y = 0; y < 4; y++)
			if (arr[y][x]) cnt++;
	return cnt;
}

void pop_right() {
	int cnt = 0, idx = 9;
	
	for (int x = 9; x >= 6; x--) {
		bool canPop = true;
		for (int y = 0; y < 4; y++) {
			if (!arr[y][x]) {
				canPop = false;
				break;
			}
		}
		if (canPop) {
			idx = min(idx, x);
			cnt++;
			for (int y = 0; y < 4; y++)
				arr[y][x] = false;
		}
	}
	
	if (cnt) {
		for (int x = idx - 1; x >= 4; x--) {
			for (int y = 0; y < 4; y++) {
				arr[y][x + cnt] = arr[y][x];
				arr[y][x] = false;
			}
		}
	}
	result += cnt;
	cnt = 0;
	
	for (int x = 4; x <= 5; x++) {
		bool avail = false;
		for (int y = 0; y < 4; y++) {
			if (arr[y][x]) {
				avail = true;
				break;
			}
		}
		if (avail) cnt++;
	}
	
	if (cnt) {
		for (int x = 9; x >= 4; x--) {
			for (int y = 0; y < 4; y++) {
				arr[y][x + cnt] = arr[y][x];
				arr[y][x] = false;
			}
		}
	}
}

void pop_down() {
	int cnt = 0, idx = 9;
	
	for (int y = 9; y >= 6; y--) {
		bool canPop = true;
		for (int x = 0; x < 4; x++) {
			if (!arr[y][x]) {
				canPop = false;
				break;
			}
		}
		if (canPop) {
			idx = min(idx, y);
			cnt++;
			for (int x = 0; x < 4; x++)
				arr[y][x] = false;
		}
	}
	if (cnt) {        //삭제할 행이 존재한다면
		for (int y = idx - 1; y >= 4; y--) {
			for (int x = 0; x < 4; x++) {
				arr[y + cnt][x] = arr[y][x];
				arr[y][x] = false;
			}
		}
	}
	result += cnt;
	cnt = 0;
	
	for (int y = 4; y <= 5; y++) {
		bool avail = false;
		for (int x = 0; x < 4; x++) {
			if (arr[y][x]) {
				avail = true;
				break;
			}
		}
		if (avail) cnt++;
	}
	
	if (cnt) {
		for (int y = 9; y >= 4; y--) {
			for (int x = 0; x < 4; x++) {
				arr[y + cnt][x] = arr[y][x];
				arr[y][x] = false;
			}
		}
	}
}

void move(int dir) {
	int m_len = 9;
	for (int k = 0; k < v.size(); k++) {
		int cx = v[k].x;
		int cy = v[k].y;
		int len = 0;
		while (1) {
			cy += dy[dir];
			cx += dx[dir];
			len++;
			if (cx == 10 || cy == 10 || arr[cy][cx]) {
				len--;
				break;
			}
		}
		m_len = min(m_len, len);
	}
	
	for (int k = 0; k < v.size(); k++) {
		int cx = v[k].x + dx[dir] * m_len;
		int cy = v[k].y + dy[dir] * m_len;
		arr[cy][cx] = true;
	}
	
	if (dir == 0) pop_down();
	else pop_right();
}

int main() {
	int query, order, x, y;
	cin >> query;
	
	for (int t = 0; t < query; t++) {
		cin >> order >> y >> x;
		v.clear();
		v.push_back({ y,x });
		if (order == 2)    v.push_back({ y,x + 1 });
		else if (order == 3)   v.push_back({ y + 1,x });
		move(0);
		move(1);
	}
    cout << result << '\n' << calculate();
}
