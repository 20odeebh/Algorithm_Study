#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>

using namespace std;

int n, m, d;
int arr[20][20];
int tmparr[20][20];
vector<pair<int, int>> peoples;
vector<pair<int, int>> zero;
int res = 0;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

bool cmp(pair<int, pair<int, int>>p1, pair<int, pair<int, int>> p2) {
	if (p1.first == p2.first)
		return p1.second.second < p2.second.second;
	return p1.first < p2.first;
}

void attack() {

	int tmparr[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			tmparr[i][j] = arr[i][j];
	}

	int cnt = 0;
	while (1) {
		vector<pair<int, pair<int, int>>>kills[3];
		// 공격 시작
		for (int i = 0; i < peoples.size(); i++) {
			int x = peoples[i].first;
			int y = peoples[i].second;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if (tmparr[k][l] == 0)
						continue;
					int tmp_dist = dist(x, y, k, l);
					if (tmp_dist <= d)
						kills[i].push_back({ tmp_dist,{k,l} });
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			sort(kills[i].begin(), kills[i].end(), cmp);
		}
		// 각 궁수가 한명씩 죽임
		for (int i = 0; i < 3; i++) {
			if (kills[i].empty())
				continue;
			int killx = kills[i][0].second.first;
			int killy = kills[i][0].second.second;
			// 같은 적 여러번 죽이는 것 방지
			if (tmparr[killx][killy] == 0)
				continue;
			tmparr[killx][killy] = 0;
			cnt++;
		}
		// 적들 이동
		bool flag = false;
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				tmparr[i + 1][j] = tmparr[i][j];
				if (tmparr[i][j] == 1)
					flag = true;
			}
		}
		for (int i = 0; i < m; i++)
			tmparr[0][i] = 0;

		if (!flag) {
			res = max(res, cnt);
			break;
		}
	}
	return;
}

void select(int idx) {
	if (peoples.size() == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				tmparr[i][j] = arr[i][j];
		}
		attack();
		return;
	}

	for (int i = idx; i < zero.size(); i++) {
		peoples.push_back(zero[i]);
		select(i + 1);
		peoples.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	// 성의 위치
	for (int i = 0; i < m; i++)
		zero.push_back({ n ,i });

	select(0);
	cout << res;
}