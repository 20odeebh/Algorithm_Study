#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>
#include<functional>
#include <set>

using namespace std;
int w, h;

int arr[51][51];
int dx[8] = { 0,1,0,-1,-1,1,-1,1 };
int dy[8] = { -1,0,1,0,-1,1,1,-1};
bool IsRange(int x, int y) {
	if (x >= 0 && x < w && y >= 0 && y < h)
		return true;
	return false;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		bool visited[51][51] = { false, };
		cin >> h >> w;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++)
				cin >> arr[i][j];
		}

		queue<pair<int, int>>q;
		int cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					cnt++;
					visited[i][j] = true;
					q.push({ i,j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 8; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (IsRange(nx,ny) && arr[nx][ny] == 1 && !visited[nx][ny]) {
								visited[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}


}

