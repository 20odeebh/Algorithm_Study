#include<bits/stdc++.h>

using namespace std;

int N, map[21][21];

int go(int x, int y, int d1, int d2) {
	vector<int> p(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				p[0] += map[r][c];
			}
		
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				p[1] += map[r][c];
			}
			
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				p[2] += map[r][c];
			}
		
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				p[3] += map[r][c];
			}
			
			else {
				p[4] += map[r][c];
			}
		}
	}

	sort(p.begin(), p.end());

	return p[4] - p[0];
}

int minDiff() {
	int res = 987654321;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					res = min(res, go(x, y, d1, d2));
				}
			}
		}
	}

	return res;
}

int main() {
	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}

	cout << minDiff() << endl;
}
