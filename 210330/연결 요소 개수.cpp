#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>

using namespace std;
int n, m;
vector<int> edge[1001];
bool visited[1001] = { false, };
int res = 0;

void dfs(int idx) {
	visited[idx] = true;
	for (auto &k : edge[idx]) {
		if (!visited[k]) {
			dfs(k);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			res++;
			dfs(i);
		}
	}
	cout << res;
}

