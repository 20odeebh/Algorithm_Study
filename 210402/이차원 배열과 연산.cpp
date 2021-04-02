// 아치원 배열과 연산

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int r, c, k, N = 3, M = 3, t = 0;
int arr[101][101], tmp[101][101];

struct Point {
	int num, cnt;
	bool operator < (const Point& p) const {
		if (this->cnt < p.cnt) return true;
		else if (this->cnt == p.cnt) {
			if (this->num < p.num) return true;
			else return false;
		}
		else return false;
	}
};

void R_operator() {
	int max_M = 0;
	for (int i = 0; i < N; i++) {
		map<int, int> m;
		for (int j = 0; j < M; j++) {
			if (!arr[i][j]) continue;
			m[arr[i][j]]++;
		}
		set<Point> s;
		for (auto& it : m) s.insert({ it.first, it.second });
		int j = 0;
		for (auto& it : s) {
			tmp[i][j++] = it.num;
			tmp[i][j++] = it.cnt;
			if (j == 100) break;
		}
		max_M = max(max_M, j);
	}
	M = max_M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = tmp[i][j];
}

void C_operator() {
	int max_N = 0;
	for (int j = 0; j < M; j++) {
		map<int, int> m;
		for (int i = 0; i < N; i++) {
			if (!arr[i][j]) continue;
			m[arr[i][j]]++;
		}
		set<Point> s;
		for (auto& it : m) s.insert({ it.first, it.second });
		int i = 0;
		for (auto& it : s) {
			tmp[i++][j] = it.num;
			tmp[i++][j] = it.cnt;
			if (i == 100) break;
		}
		max_N = max(max_N, i);
	}
	N = max_N;
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
			arr[i][j] = tmp[i][j];
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf(" %d", &arr[i][j]);
	while (t <= 100) {
		if (arr[r - 1][c - 1] == k) break;
		memset(tmp, 0, sizeof(tmp));
		if (N >= M) R_operator();
		else C_operator();
		t++;
	}
	if (t == 101) t = -1;
	printf("%d\n", t);
	return 0;
}