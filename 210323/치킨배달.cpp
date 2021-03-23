#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;
int n, m;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>>house;
vector<pair<int, int>> selected_chi;
bool selected[15] = { false, };
int res = INT_MAX;

void dfs(int idx, int cnt) {
	// m개 모두 골랐을 때 치킨 거리 계산
	if (cnt == m) {
		int total = 0;
		for (auto &k : house) {
			int x = k.first;
			int y = k.second;
			int tmp = 100;
			for (auto &l : selected_chi) {
				tmp = min(tmp, abs(y - l.second) + abs(x - l.first));
			}
			total += tmp;
		}
		res = min(total, res);
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			selected_chi.push_back({ chicken[i].first, chicken[i].second });
			dfs(i + 1, cnt + 1);
			selected_chi.pop_back();
			selected[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				house.push_back({ i,j });
			if (arr[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	dfs(0,0);

	cout << res;
}