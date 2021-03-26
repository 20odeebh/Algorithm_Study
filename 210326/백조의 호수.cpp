#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>

using namespace std;
int r, c;
char arr[1501][1501];
int dist[1501][1501] = { INT_MAX };
bool visited[1501][1501];
bool checked[1501][1501];
vector<pair<int, int>>pos;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int res = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

void initChecked() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			checked[i][j] = false;
	}
}
void initVisited() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			visited[i][j] = false;
	}
}


int getTime() {
	initVisited();
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

	pq.push({ 0,{ pos[0].first,pos[0].second } });
	visited[pos[0].first][pos[0].second] = true;
	int maxTime = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		//cout << cur << ' ' << x << ' ' << y << endl;
		maxTime = max(cur, maxTime);
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				if (nx == pos[1].first && ny == pos[1].second)
					return maxTime;
				pq.push({ dist[nx][ny],{ nx,ny } });
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	queue<pair<int, int>>q;


	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
			if (str[j] == 'L') {
				pos.push_back({ i,j });
				arr[i][j] = '.';
			}
			if (arr[i][j] == '.') {
				dist[i][j] = 0;
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}


	cout << getTime();

}
