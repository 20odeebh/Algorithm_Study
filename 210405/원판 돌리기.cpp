// 원판 돌리기

#include <stdio.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

int n, m, t;
deque<int> dq[52];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void turn_dq(int x, int& d, int k) {
	for (int i = x; i <= n; i += x) {
		for (int j = 0; j < k; j++) {
			if (d) {
				dq[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
			else {
				dq[i].push_front(dq[i].back());
				dq[i].pop_back();
			}
		}
	}
}

void find() {
	bool del = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (!dq[i][j]) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			int del_cnt = 0;
			int val = dq[i][j];
			dq[i][j] = 0;
			int y, x, ny, nx;
			while (!q.empty()) {
				y = q.front().first;
				x = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny == 0 || ny == n + 1) continue;
					if (nx < 0) nx = m - 1;
					if (nx == m) nx = 0;
					if (!dq[ny][nx] || dq[ny][nx] != val) continue;
					q.push(make_pair(ny, nx));
					dq[ny][nx] = 0;
					del_cnt++;
					del = true;
				}
			}
			if (!del_cnt) dq[i][j] = val;
		}
	}
	if (del) return;

	int total = 0, total_cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j]) {
				total_cnt++;
				total += dq[i][j];
			}
		}
	}
	double avg = (double)total / (double)total_cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (!dq[i][j]) continue;
			if ((double)dq[i][j] < avg) dq[i][j]++;
			else if ((double)dq[i][j] > avg) dq[i][j]--;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		dq[i].resize(m);
		for (int j = 0; j < m; j++)
			scanf(" %d", &dq[i][j]);
	}
	while (t--) {
		int x, d, k;
		scanf(" %d %d %d", &x, &d, &k);
		turn_dq(x, d, k);
		find();
	}
	int total = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			total += dq[i][j];
	printf("%d\n", total);
	return 0;
}