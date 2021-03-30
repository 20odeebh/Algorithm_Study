// 연결 요소의 개수

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <set>

int n, m;
int parent[1001];
std::set<int> s;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int y, int x) {
	y = Find(y);
	x = Find(x);
	if (y == x) return;
	else if (y > x) parent[y] = x;
	else parent[x] = y;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int start, end;
		scanf(" %d %d", &start, &end);
		Union(start, end);
	}
	for (int i = 1; i <= n; i++) s.insert(Find(parent[i]));
	printf("%d\n", (int)s.size());
	return 0;
}