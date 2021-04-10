// 낚시왕

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int r, c, m;
int arr[101][101], tmp[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

struct SHARK {
	bool die;
	int y, x, s, d, z;
};
vector<SHARK> v;

void move_shark() {
	memset(tmp, -1, sizeof(tmp));
	for (int idx = 0; idx < m; idx++) {
		if (v[idx].die) continue;
		int y = v[idx].y;
		int x = v[idx].x;
		int s = v[idx].s;
		int d = v[idx].d;

		if (d < 2) s %= (2 * (r - 1));
		else s %= (2 * (c - 1));

		for (int i = 0; i < s; i++) {
			y += dy[d];
			x += dx[d];
			if (y < 0 || y == r || x < 0 || x == c) {
				if (d % 2) d--;
				else d++;
				y += (dy[d] * 2);
				x += (dx[d] * 2);
			}
		}
		if (tmp[y][x] >= 0) {
			v[idx].die = true;
			continue;
		}
		tmp[y][x] = idx;
		v[idx].y = y;
		v[idx].x = x;
		v[idx].d = d;
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = tmp[i][j];
}

int catch_shark() {
	int ret = 0;
	for (int x = 0; x < c; x++) {
		for (int y = 0; y < r; y++) {
			if (arr[y][x] >= 0) {
				ret += v[arr[y][x]].z;
				v[arr[y][x]].die = true;
				arr[y][x] = -1;
				break;
			}
		}
		move_shark();
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &r, &c, &m);
	v.resize(m);
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < m; i++) {
		int y, x, s, d, z;
		scanf(" %d %d %d %d %d", &y, &x, &s, &d, &z);
		v[i] = { false, y - 1, x - 1, s, d - 1, z };
	}
	sort(v.begin(), v.end(), [](SHARK& s1, SHARK& s2) {
		return s1.z > s2.z;
	});
	for (int i = 0; i < m; i++) arr[v[i].y][v[i].x] = i;

	printf("%d\n", catch_shark());
	return 0;
}