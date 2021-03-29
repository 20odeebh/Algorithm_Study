// 최단경로

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>

int V, E, K;
int visited[20001];
std::vector<std::pair<int, int>> v[20001];

void bfs() {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(0, K));
	for (int i = 1; i <= V; i++) visited[i] = INT_MAX;
	visited[K] = 0;

	int node, d, nd;
	while (!pq.empty()) {
		node = pq.top().second;
		d = -pq.top().first;
		pq.pop();
		if (visited[node] < d) continue;

		for (auto& next : v[node]) {
			nd = d + next.second;
			if (nd > visited[next.first]) continue;
			pq.push(std::make_pair(-nd, next.first));
			visited[next.first] = nd;
		}
	}
}

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 0; i < E; i++) {
		int start, end, distance;
		scanf("%d %d %d", &start, &end, &distance);
		v[start].push_back(std::make_pair(end, distance));
	}
	bfs();
	for (int i = 1; i <= V; i++) {
		if (visited[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", visited[i]);
	}
	return 0;
}