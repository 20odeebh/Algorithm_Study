#include <iostream>
#include <vector>

using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };
int w, h;

vector<vector<int>> map;
vector<vector<int>> visited;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= h || ny < 0 || ny >= w)
			continue;
		else {
			if (map[nx][ny] == 1 && visited[nx][ny] == 0)
				dfs(nx, ny);
		}
	}
}

int main(){
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
        
		for (int i = 0; i < h; i++) {
			vector<int> map_row;
			vector<int> visited_row;

			for (int j = 0; j < w; j++) {
				int num;
				cin >> num;
				map_row.push_back(num);
				visited_row.push_back(0);
			}
			map.push_back(map_row);
			visited.push_back(visited_row);
		}
        
		int cnt = 0;
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					cnt++;
					dfs(i, j);

				}
			}
		}
		cout << cnt << endl;

		map.clear();
		visited.clear();
	}
}
