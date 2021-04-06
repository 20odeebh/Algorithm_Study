#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int N, M, fuel;
int map[21][21];
int vis[21][21];
int bx, by;
int guest[401][4];
int res;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int num, loc;
int flag;
struct compare {
	bool operator()(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
		if (a.second == b.second) {
			if (a.first.first == b.first.first) {
				return a.first.second > b.first.second;
			}
			return a.first.first > b.first.first;
		}
		return a.second > b.second;
	}
};
void solve(int x, int y, int dis) {
	//	queue<pair<pair<int, int>, int>> pq;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> pq;
	pq.push({ { x,y },dis });

	while (!pq.empty()) {
		int cx = pq.top().first.first;
		int cy = pq.top().first.second;
		int dis = pq.top().second;
		for (int i = 1; i <= M; i++) {
			if (guest[i][0] != -1 && cx == guest[i][0] && cy == guest[i][1]) {
				num = i;
				loc = dis;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (map[nx][ny] == 0 && vis[nx][ny] == 0 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
				vis[nx][ny] = 1;
				pq.push({ { nx,ny },dis + 1 });

			}
		}
	}


}

void move(int x, int y, int dis) {
	//queue<pair<pair<int, int>, int>> qq;
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> qq;
	qq.push({ { x,y },dis });

	while (!qq.empty()) {
		int cx = qq.top().first.first;
		int cy = qq.top().first.second;
		int dis = qq.top().second;

		if (cx == guest[num][2] && cy == guest[num][3]) {
			loc = dis;
			flag = 1;
			break;
		}
		if (flag == 1) break;
		qq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (map[nx][ny] == 0 && vis[nx][ny] == 0 && nx > 0 && ny > 0 && nx <= N && ny <= N) {
				vis[nx][ny] = 1;
				qq.push({ { nx,ny },dis + 1 });
			}
		}
	}
}
int main() {
	res = -1;
	scanf("%d%d%d", &N, &M, &fuel);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d%d", &bx, &by);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &guest[i][0]);
		scanf("%d", &guest[i][1]);

		scanf("%d", &guest[i][2]);
		scanf("%d", &guest[i][3]);
	}

	for (int i = 1; i <= M; i++) {
		flag = 0;
		memset(vis, 0, sizeof(vis));
		solve(bx, by, 0);

		bx = guest[num][0];
		by = guest[num][1];
		guest[num][0] = -1;
		fuel -= loc;
		if (fuel < 0 || flag == 0) break;

		memset(vis, 0, sizeof(vis));
		flag = 0;
		move(bx, by, 0);
		bx = guest[num][2];
		by = guest[num][3];
		fuel -= loc;
		if (fuel < 0 || flag == 0) break;

		fuel += loc * 2;
	}

	if (fuel >= 0 && flag == 1)
		res = fuel;

	printf("%d", res);

}