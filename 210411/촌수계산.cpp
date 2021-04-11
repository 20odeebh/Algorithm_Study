// 촌수계산

#include <stdio.h>
#include <vector>

using namespace std;

int n, m, start, last, res = 0;
bool visited[101];
vector<int> v[101];

void dfs(int idx, int cnt) {
	if (idx == last) {
		res = cnt;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		if (!visited[v[idx][i]]) {
			visited[v[idx][i]] = true;
			dfs(v[idx][i], cnt + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf(" %d %d", &start, &last);
	scanf(" %d", &m);
	while (m--) {
		int node1, node2;
		scanf(" %d %d", &node1, &node2);
		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}
	dfs(start, 0);
	if (res == 0) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}