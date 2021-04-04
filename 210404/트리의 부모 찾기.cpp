// 트리의 부모 찾기

#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;

int n;
int parent[MAX + 1];
vector<int> v[MAX + 1];

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int& next : v[node]) {
			if (!parent[next]) {
				q.push(next);
				parent[next] = node;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int node1, node2;
		scanf(" %d %d", &node1, &node2);
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	parent[1] = 1;
	bfs();
	for (int i = 2; i <= n; i++) printf("%d\n", parent[i]);
	return 0;
}