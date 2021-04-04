#include <iostream>
#include <string>
#include<cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <map>
#include<functional>
#include <climits>
#include <stack>

using namespace std;
// 11분
int n, m;
int arr[51][51];
bool selected[20] = { false, };
int dist[51][51];
bool visited[51][51];
int res = INT_MAX;
vector<pair<int, int>>location;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool flag = false;

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

void Init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			dist[i][j] = -1;
		}
	}
}

int maxTime() {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 빈칸인데 아직 방문하지 않은 곳이 있다면 끝
			if (arr[i][j] == 0)
				ans = max(ans, dist[i][j]);
		}
	}
	return ans;
}

bool IsEnd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 빈칸인데 아직 방문하지 않은 곳이 있다면 끝
			if (arr[i][j] == 0 && dist[i][j]==-1)
				return false;
		}
	}
	return true;
}

void bfs() {
	// 선택된 애들 queue에 넣기 
	Init();

	queue<pair<int, int>>q;

	// 선택된 바이러스 queue에 넣기
	for (int i = 0; i < location.size(); i++) {
		if (selected[i]) {
			visited[location[i].first][location[i].second] = true;
			q.push({ location[i].first,location[i].second });
			dist[location[i].first][location[i].second] = 0;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			// 비활성 바이러스에 대한 처리 놓침
			// 활성 바이러스가 빈칸 뿐만 아니라 비활성 바이러스에 대해서도 영향을 주기 때문에
			// queue에 넣어주어야한다.
			if (IsRange(nx, ny) && !visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny]==2)) {
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	// BFS 계산을 끝낸 후에 확인하자 
	// -> 시간초과
	if (IsEnd()) {
		flag = true;
		res = min(res, maxTime());
		return;
	}
}


void dfs(int idx, int cnt) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = idx; i < location.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			dfs(i + 1, cnt + 1);
			selected[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				location.push_back({ i,j });
		}
	}

	//location 중에서 바이러스 m개 활성화하자
	dfs(0, 0);

	if (!flag)
		cout << -1;
	else
		cout << res;
}