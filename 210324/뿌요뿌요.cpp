#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>


using namespace std;
char arr[12][6];
bool visited[12][6];
bool bombed[12][6];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int res = 0;

bool IsRange(int x, int y) {
	if (x >= 0 && x < 12 && y >= 0 && y < 6)
		return true;
	return false;
}

void initVisited() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			bombed[i][j] = false;
			visited[i][j] = false;
		}
	}
	return;
}
void printP() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			cout << arr[i][j];
		cout << endl;
	}
	cout << endl;
}
void bombPuyo() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (bombed[i][j]) {
				arr[i][j] = '.';
			}
		}
	}
	//printP();
	return;
}

void downPuyo() {
	// 아래서부터 확인하면서 내리기
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				char cur = arr[i][j];
				arr[i][j] = '.';
				int nx = i;
				// 내리기
				while (nx + 1 < 12 && arr[nx + 1][j] == '.')
					nx++;
				arr[nx][j] = cur;
			}
		}
	}
	//printP();
}

void goPuyo() {
	
	initVisited();

	bool flag = false;
	// 4개 이상 연결되었는가?
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (arr[i][j] != '.') {
				// bfs로 몇개인지 확인하기
				char target = arr[i][j];
				visited[i][j] = true;
				queue<pair<int, int>>q;
				q.push({ i,j });
				int cnt = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (IsRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == target) {
							q.push({ nx,ny });
							cnt++;
							visited[nx][ny] = true;
						}
					}
				}
				// 한번에 터져야하기 때문에 다시 bfs 사용해서 터질 예정인 곳 체크
				if (cnt >= 4) {
					flag = true;
					// visited 처리하기 
					bombed[i][j] = true;
					queue<pair<int, int>>tmp;
					tmp.push({ i,j });
					while (!tmp.empty()) {
						int x = tmp.front().first;
						int y = tmp.front().second;
						tmp.pop();
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (IsRange(nx, ny) && !bombed[nx][ny] && arr[nx][ny] == target) {
								tmp.push({ nx,ny });
								bombed[nx][ny] = true;
							}
						}
					}
				}
			}
		}
	}

	if (!flag) {
		cout << res;
		exit(0);
	}

	// 터트리기 
	bombPuyo();

	// 내리기
	downPuyo();

	res++;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		string str; cin >> str;
		for (int j = 0; j < 6; j++)
			arr[i][j] = str[j];
	}

	while (1) {
		goPuyo();
	}
}
