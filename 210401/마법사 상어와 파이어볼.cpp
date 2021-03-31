// 마법사 상어와 파이어볼

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, c, k;
int arr[51][51];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
struct Point{
	int m, s, d;
};
vector<Point> v[51][51], tmp[51][51];

void devide_and_conquer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].empty()) continue;
			if (tmp[i][j].size() == 1) v[i][j].push_back(tmp[i][j][0]);
			else {
				int m = 0;
				int s = 0;
				bool odd = false;
				bool even = false;
				for (auto& it : tmp[i][j]) {
					m += it.m;
					s += it.s;
					if (it.d % 2) odd = true;
					else even = true;
				}
				m /= 5;
				if (m) {
					s /= tmp[i][j].size();
					int d = 0;
					if (odd && even) d = 1;
					for (int dd = d; dd < 8; dd += 2)
						v[i][j].push_back({ m, s, dd });
				}
			}
			tmp[i][j].clear();
		}
	}
}

void move() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].empty()) continue;
			for (auto& it : v[i][j]) {
				int m = it.m;
				int s = it.s;
				int d = it.d;
				int y = i + n;
				int x = j + n;
				y = (y + (dy[d] * (s % n))) % n;
				x = (x + (dx[d] * (s % n))) % n;
				tmp[y][x].push_back({ m, s, d });
			}
			v[i][j].clear();
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &c, &k);
	for (int i = 0; i < c; i++) {
		int y, x, m, s, d;
		scanf(" %d %d %d %d %d", &y, &x, &m, &s, &d);
		v[y - 1][x - 1].push_back({ m, s, d });
	}
	while (k--) {
		move();
		devide_and_conquer();
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (auto& it : v[i][j])
				res += it.m;
	printf("%d\n", res);
	return 0;
}