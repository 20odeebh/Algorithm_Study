#include <bits/stdc++.h>
using namespace std;
vector<int> v[1001];
bool check[1001];
// 연결요소란 서로 연결되지 않는 그래프들의 갯수이다.
// dfs로 센다.
void dfs(int x) {
	check[x] = true;
	for (auto k : v[x]) {
		if (check[k] == false) {
			dfs(k);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << '\n';
}