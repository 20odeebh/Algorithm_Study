#include <bits/stdc++.h>

using namespace std;

int n, m, h, rs = 100, arr[31][11];

vector<pair<int, int>> v;

bool check() {
	bool flag = true;

	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (arr[j][pos] == 1)pos++;
			else if (arr[j][pos - 1] == 1)pos--;
			else;
		}
		if (pos != i) return flag = false;
	}
	return flag;
}

void pick(int cur, int cnt, int l) {
	if (cnt == l) {
		if (check()) {
			rs = min(l, rs);
		}
		return;
	}
  
	for (int i = cur; i < v.size(); i++) {
		if (!arr[v[i].first][v[i].second] && !arr[v[i].first][v[i].second - 1] && !arr[v[i].first][v[i].second + 1]) {
			arr[v[i].first][v[i].second] = 1;
			pick(i + 1, cnt + 1, l);
			arr[v[i].first][v[i].second] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
  
	for (int i = 0; i <= 3; i++) {
		pick(0, 0, i);
	}
  
	if (rs == 100)cout << -1;
	else cout << rs;
}
