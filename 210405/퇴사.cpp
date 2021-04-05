// 퇴사

#include <stdio.h>
#include <algorithm>

int n, res = 0;
int arr[15][2];

void dfs(int day, int total) {
	if (day >= n) {
		res = res < total ? total : res;
		return;
	}
	if(day + arr[day][0] <= n) dfs(day + arr[day][0], total + arr[day][1]);
	dfs(day + 1, total);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d %d", &arr[i][0], &arr[i][1]);
	dfs(0, 0);
	printf("%d\n", res);
	return 0;
}