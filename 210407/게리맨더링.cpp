#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, p[11], net[11][11],selected[11],res=987654321;

void cal() {
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (selected[i])	a+=p[i];
		else b += p[i];
	}
	int diff = abs(a - b);
	if (diff < res)res = diff;
}

bool connected(vector<int> v, int t) {
	queue<int> q;
	q.push(v.front());
	int visit[11] = { 0, };
	visit[v.front()] = 1;	
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (net[x][i] == 1 && selected[i] == t && visit[i] == 0) {
				q.push(i);
				cnt++;
				visit[i] = 1;
			}
		}
	}
	if (cnt == v.size())return true;
	else return false;
}

bool check() {
	vector<int> a, b;
	for (int i = 1; i <= n; i++) {
		if (selected[i])	a.push_back(i);
		else b.push_back(i);
	}
	if (a.size() == 0 || b.size() == 0)return false;
	if (!connected(a,1 )) return false;
	if (!connected(b,0 )) return false;
	return true;

}

void dfs(int cur, int cnt) {
	if (cnt >= 1) {
		if (check()) {
			cal();
		}
	}
	for (int i = cur; i <= n; i++) {
		if (selected[i])continue;
		selected[i] = 1;
		dfs(i, cnt + 1);
		selected[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for (int j = 1; j <= t; j++) {
			int to;
			cin >> to;
			net[i][to] = 1;
		}
	}
	
	dfs(1, 0);
	if (res == 987654321)cout << -1;
	else cout << res;
}
