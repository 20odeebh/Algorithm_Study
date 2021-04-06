// 근손실

#include <stdio.h>

int n, k, res = 0;
int arr[8];
bool visited[8];

void dfs(int weight, int day) {
	if (day == n) {
		res++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i] && weight - k + arr[i] >= 500) {
			visited[i] = true;
			dfs(weight - k + arr[i], day + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
	dfs(500, 0);
	printf("%d\n", res);
	return 0;
}