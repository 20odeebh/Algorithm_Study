// 연산자 끼워넣기

#include <stdio.h>
#include <limits.h>
#include <algorithm>

int n, min_res = INT_MAX, max_res = -INT_MAX;
int arr[101];
int command[4];

void dfs(int cnt, int total) {
	if (cnt == n) {
		min_res = std::min(min_res, total);
		max_res = std::max(max_res, total);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (command[i]) {
			command[i]--;
			if (i == 0) dfs(cnt + 1, total + arr[cnt]);
			else if (i == 1) dfs(cnt + 1, total - arr[cnt]);
			else if (i == 2) dfs(cnt + 1, total * arr[cnt]);
			else dfs(cnt + 1, total / arr[cnt]);
			command[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	for (int i = 0; i < 4; i++) scanf(" %d", &command[i]);
	dfs(1, arr[0]);
	printf("%d\n%d\n", max_res, min_res);
	return 0;
}