// 원자 소멸 시뮬레이션

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int n, res;
int arr[4005][4005];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
struct Point {
	bool die;
	int y, x, d, k;
};
vector<Point> v;

void move() {
	int cnt = n;
	while (cnt) {
		for (int i = 1; i <= n; i++) {
			if (v[i].die) continue;
			int& y = v[i].y;
			int& x = v[i].x;
			int d = v[i].d;

			arr[y][x] = 0;
			y += dy[d];
			x += dx[d];
			if (y < 0 || y > 4000 || x < 0 || x > 4000) {
				v[i].die = true;
				cnt--;
				continue;
			}
			arr[y][x] += i;
		}

		for (int i = 1; i <= n; i++) {
			if (v[i].die) continue;
			int y = v[i].y;
			int x = v[i].x;
			if (arr[y][x] == i) continue;
			v[i].die = true;
			res += v[i].k;
			arr[y][x] = 0;
			cnt--;
		}
	}
}

int main() {
	int T;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf(" %d", &n);
		res = 0;
		v.clear();
		v.resize(n + 1);
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			int y, x, d, k;
			scanf(" %d %d %d %d", &x, &y, &d, &k);
			v[i] = { false, (y + 1000) * 2, (x + 1000) * 2, d, k };
			arr[v[i].y][v[i].x] = i;
		}
		move();
		printf("#%d %d\n", tc, res);
	}
	return 0;
}