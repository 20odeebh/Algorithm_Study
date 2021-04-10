#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>

using namespace std;
// 35분
int n;
vector<int> edge[101];
bool visited[101] = { false, };
int a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> a >> b;
	int m; cin >> m;
	while (m--) {
		int par, child; cin >> par >> child;
		edge[par].push_back(child);
		edge[child].push_back(par);
	}

	queue<pair<int, int>>q;
	q.push({ a,0 });
	visited[a] = true;
	bool flag = false;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == b) {
			flag = true;
			cout << cnt;
			break;
		}
		for (auto &k : edge[cur]) {
			if (!visited[k]) {
				visited[k] = true;
				q.push({ k,cnt + 1 });
			}
		}
	}
	if(!flag)
		cout << -1;

}