#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector <vector <int>> graph(100001);
int parent[100001] = { 0, };

void dfs(int idx) {
	for (auto &k : graph[idx]) {
		if (!parent[k]) {
			parent[k] = idx;
			dfs(k);
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

}