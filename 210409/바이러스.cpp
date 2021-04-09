// 바이러스

#include <stdio.h>

int n, m;
int arr[101];

int Find(int x) {
	if (x == arr[x]) return x;
	else return arr[x] = Find(arr[x]);
}

int main() {
	scanf("%d", &n);
	scanf(" %d", &m);
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		int node1, node2;
		scanf(" %d %d", &node1, &node2);
		node1 = Find(node1);
		node2 = Find(node2);
		if (node1 == node2) continue;
		if (node1 < node2) arr[node2] = node1;
		else arr[node1] = node2;
	}
	int res = 0;
	for (int i = 2; i <= n; i++)
		if (Find(arr[i]) == 1) res++;
	printf("%d\n", res);
	return 0;
}