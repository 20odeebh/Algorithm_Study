#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

// 종료조건: 상어보다 크기가 작은 물고기가 없는 경우
// 거리는 지나야하는 칸의 최소 개수 (bfs로 구하기)
// 1. 현재 아기상어의 위치와 크기에서 먹을 수 있는 상어 정렬하기
// 2. 먹고 이동하기 (크기 커지는 것을 위해 몇마리 먹었는지 따로 정리)

int sx, sy, ssize;

struct FISH {
	int x, y, dist;
};

int n;
int res = 0;

int arr[21][21];
int cur_eat = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}
// 정렬 조건, 거리 짧은 순, x좌표 작은 순, y좌표 작은 순
bool cmp(FISH f1, FISH f2) {
	if (f1.dist == f2.dist) {
		if (f1.x == f2.x) {
			return f1.y < f2.y;
		}
		else
			return f1.x < f2.x;
	}
	else
		return f1.dist < f2.dist;
}

void find_fish() {

	// 현재 위치에서 나머지 물고기까지
	queue<FISH>q;
	vector<FISH> tmp;
	bool visited[21][21] = { false, };

	q.push({ sx,sy,0 });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cur_dist = q.front().dist;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 크기가 작거나 같으면 이동 가능
			if (IsRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] <= ssize) {
				// 물고기 중, 크기가 작은 값은 먹을 수 있는 후보이기 때문에 저장
				if (arr[nx][ny] != 0 && arr[nx][ny]<ssize) {
					tmp.push_back({ nx,ny,cur_dist + 1 });
				}
				visited[nx][ny] = true;
				q.push({ nx,ny,cur_dist + 1 });
			}
		}
	}
	// 먹을 수 있는 물고기가 없으면 끝내기
	if (tmp.empty()) {
		cout << res;
		exit(0);
	}

	sort(tmp.begin(), tmp.end(), cmp);

	// 정렬 후, 1마리의 물고기 먹기
	sx = tmp.front().x;
	sy = tmp.front().y;
	res += tmp.front().dist;
	cur_eat += 1;
	arr[sx][sy] = 0;

	if (cur_eat == ssize) {
		cur_eat = 0;
		ssize += 1;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				ssize = 2;
				arr[i][j] = 0;
			}
		}
	}

	while (1) {
		find_fish();
	}


}