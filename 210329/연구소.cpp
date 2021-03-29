#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>
#include <stack>

using namespace std;
// 45분
// N,M의 범위 작음 : 브루트 포스로 모든 경우의 수 진행 
// 1. 3개 선택 - 조합
// 2. 바이러스 퍼트리기 - BFS
// 3. 안전영역의 넓이 구하기 - for문 사용

int arr[10][10];
int tmp_arr[10][10];
int n, m;
int res = 0;
bool visited[10][10] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

vector<pair<int, int>> virus;
vector<pair<int, int>>tmp;
vector<pair<int, int>>selected;


bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
void initArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_arr[i][j] = arr[i][j];
			visited[i][j] = false;
		}
	}
}

int calSafe() {

	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_arr[i][j] == 0)
				total++;
		}
	}
	return total;
}

void goVirus() {

	initArr();

	queue<pair<int, int>>q;
	for (auto &k : virus) {
		q.push({ k.first,k.second });
		visited[k.first][k.second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx, ny) && !visited[nx][ny] && tmp_arr[nx][ny] == 0) {
				tmp_arr[nx][ny] = 2;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	return;
}

void select(int idx, int cnt) {
	if (cnt == 3) {
		for (auto &k : selected) {
			arr[k.first][k.second] = 1;
		}
		goVirus();
		res = max(res, calSafe());
		for (auto &k : selected) {
			arr[k.first][k.second] = 0;
		}
		return;
	}

	for (int i = idx; i < tmp.size(); i++) {
		selected.push_back({ tmp[i].first, tmp[i].second });
		select(i + 1, cnt + 1);
		selected.pop_back();
	}

}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				tmp.push_back({ i,j });
			else if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	
	

	select(0, 0);
	cout << res;
}

