#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int test_case, n, m, k;
int arr[405][405];

class Point {
public:
	int y, x, cnt, size;
};
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
vector<Point> v;

void spread() {
	int y, x, ny, nx, len;
	while (k--) {
		len = v.size();
		sort(v.begin(), v.end(), [](Point p1, Point p2) {
			return p1.size > p2.size;
		});
		for (int i = 0; i < len; i++) {
			if (v[i].size == -16) {
				v.erase(v.begin() + i, v.begin() + len);
				break;
			}
			if (v[i].cnt == 0) {
				y = v[i].y;
				x = v[i].x;
				for (int j = 0; j < 4; j++) {
					ny = y + dy[j];
					nx = x + dx[j];
					if (!arr[ny][nx]) {
						arr[ny][nx] = v[i].size;
						v.push_back({ ny, nx, v[i].size, v[i].size });
					}
				}
			}
			v[i].cnt--;
			if (-v[i].cnt == v[i].size) v[i].size = -16;
		}
	}
	sort(v.begin(), v.end(), [](Point p1, Point p2) {
		return p1.size > p2.size;
	});
	len = v.size();
	for (int i = 0; i < len; i++) {
		if (v[i].size == -16) {
			v.erase(v.begin() + i, v.end());
			break;
		}
	}
}

int main() {
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		memset(arr, 0, sizeof(arr));
		v.clear();
		scanf(" %d %d %d", &n, &m, &k);
		for (int i = 151; i < n + 151; i++) {
			for (int j = 151; j < m + 151; j++) {
				scanf(" %d", &arr[i][j]);
				if (arr[i][j]) v.push_back({ i, j, arr[i][j], arr[i][j] });
			}
		}
		spread();
		printf("#%d %d\n", tc, v.size());
	}
	return 0;
}