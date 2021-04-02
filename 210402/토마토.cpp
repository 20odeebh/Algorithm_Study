#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int m, n, h;
int arr[101][101][101];
bool visited[101][101][101] = { false, };

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

struct pos {
	int x;
	int y;
	int z;
};

queue<pos> q;
int res = 0;

bool IsGo(int x, int y, int z) {
	if (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < h && !visited[x][y][z] && arr[x][y][z] == 0)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> h;
	int firstTo = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[j][k][i];
				if (arr[j][k][i] == 1) {
					q.push({ j,k,i });
					visited[j][k][i] = true;
				}
				if (arr[j][k][i] == 0)
					firstTo++;
			}
		}
	}


	if (firstTo == 0)
	{
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (IsGo(nx, ny, nz)) {
				q.push({ nx,ny,nz });
				visited[nx][ny][nz] = true;
				arr[nx][ny][nz] = arr[x][y][z] + 1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k][i] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				res = max(res, arr[j][k][i]);
			}
		}
	}

	cout << res-1;

}