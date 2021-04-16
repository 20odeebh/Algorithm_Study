// 점심 식시시간

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <limits.h>

using namespace std;

int n, ret;
int arr[11][11], sequnce[11];
pair<int, int> door[2];
vector<pair<int, int>> v;

void stair() {
	priority_queue<int> pq_1, pq_2;
	for (int i = 0; i < v.size(); i++) {
		int dis;
		if (sequnce[i]) {
			dis = abs(door[0].first - v[i].first) + abs(door[0].second - v[i].second);
			pq_1.push(-dis);
		}
		else {
			dis = abs(door[1].first - v[i].first) + abs(door[1].second - v[i].second);
			pq_2.push(-dis);
		}
	}

	int len, t = 0;
	queue<int> q_1, q_2;
	while (!pq_1.empty() || !pq_2.empty()) {
		if (++t == ret) return;
		
		len = q_1.size();
		while (len--) {
			int num = q_1.front();
			q_1.pop();
			if (num) q_1.push(num - 1);
		}
		len = q_2.size();
		while (len--) {
			int num = q_2.front();
			q_2.pop();
			if (num) q_2.push(num - 1);
		}

		while (!pq_1.empty()) {
			int num = -pq_1.top();
			if (num <= t && q_1.size() < 3) {
				pq_1.pop();
				if (num == t) q_1.push(arr[door[0].first][door[0].second]);
				else q_1.push(arr[door[0].first][door[0].second] - 1);
				continue;
			}
			break;
		}
		while (!pq_2.empty()) {
			int num = -pq_2.top();
			if (num <= t && q_2.size() < 3) {
				pq_2.pop();
				if (num == t) q_2.push(arr[door[1].first][door[1].second]);
				else q_2.push(arr[door[1].first][door[1].second] - 1);
				continue;
			}
			break;
		}
	}

	while (!q_1.empty() || !q_2.empty()) {
		if (++t == ret) return;
		
		len = q_1.size();
		while (len--) {
			int num = q_1.front();
			q_1.pop();
			if (num) q_1.push(num - 1);
		}
		len = q_2.size();
		while (len--) {
			int num = q_2.front();
			q_2.pop();
			if (num) q_2.push(num - 1);
		}
	}
	ret = ret > t ? t : ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int idx = 0;
		ret = INT_MAX;
		v.clear();
		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &arr[i][j]);
				if (arr[i][j] == 1) v.push_back(make_pair(i, j));
				else if (arr[i][j] > 1) door[idx++] = make_pair(i, j);
			}
		}
		memset(sequnce, 0, sizeof(sequnce));
		for (int i = v.size(); i >= 0; i--) {
			if (i != v.size()) sequnce[i] = 1;
			do {
				stair();
			} while (next_permutation(sequnce, sequnce + v.size()));
		}
		printf("#%d %d\n", tc, ret);
	}
	return 0;
}