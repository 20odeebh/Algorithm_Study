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
// 15분
int n, m, k;
int add[11][11];
int arr[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int res = 0;

// 각 위치별 나무의 나이를 저장할 pq
deque<int>tree[11][11];
deque<int>dead_tree[11][11];

bool IsRange(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= n)
		return true;
	return false;
}

void Spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = tree[i][j].size();
			while (size--) {
				int age = tree[i][j].front(); tree[i][j].pop_front();
				if (arr[i][j] >= age) {
					arr[i][j] -= age;
					tree[i][j].push_back(age + 1);
				}
				else
					dead_tree[i][j].push_back(age);
			}
		}
	}
	return;
}

void Summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 현재 위치의 죽은 나무들 양분으로 변한다.
			int size = dead_tree[i][j].size();
			while (size--) {
				arr[i][j] += (dead_tree[i][j].front() / 2);
				dead_tree[i][j].pop_front();
			}
		}
	}
	return;
}

void Fall() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (!IsRange(nx, ny))
							continue;
						tree[nx][ny].push_front(1);
					}
				}
			}
		}
	}
	return;
}

void Winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += add[i][j];
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	// 매번 더해지는 양분의 양
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> add[i][j];
			arr[i][j] = 5;
		}
	}

	while (m--) {
		int x, y, age; cin >> x >> y >> age;
		tree[x][y].push_back(age);
	}

	while (k--) {
		Spring();
		Summer();
		Fall();
		Winter();

	}
	// 나무의 개수 세기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 현재 위치의 나무들
			res += tree[i][j].size();
		}
	}
	cout << res;
}