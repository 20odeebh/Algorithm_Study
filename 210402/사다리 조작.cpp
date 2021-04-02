#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
// 38분
// 40분

int n, h, m;
// 모든 조합 진행 
// BF
// 가로선 만나면 이동해야한다.  
int arr[40][40];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool visited[40][40] = { false, };
bool selected[40][40] = { false, };

// 배열 시작점에 끝 y좌표를 저장하자

// 각 세로선에 대해서 최종으로 가는 곳이 모두 i번인지 판단하는 함수
bool canGo() {
	for (int i = 1; i <= n; i++) {
		int x, y;
		x = 1, y = i;
		memset(visited, false, sizeof(visited));
		while (1) {
			//cout << x << ' ' << y << endl;
			visited[x][y] = true;
			// 내려가다가 선이 어느 위치에 존재하는지 확인하고 
			// 방향을 돌린다.
			// x 증가 y는 그대로로 일단 이동
			// 똑같은 곳 방문하면 안됨
			
			// 내가 y+1에 연결되어 있고 
			// y+1도 나와 연결되어 있을 때

			if (y + 1 <= n && arr[x][y] == y + 1 && arr[x][y + 1] == y && !visited[x][y + 1])
				y += 1;
			else if (y-1>0 && arr[x][y] == y - 1 && arr[x][y - 1] == y && !visited[x][y-1])
				y -= 1;
			else
				x += 1;
			// 끝나는 조건, x가 끝까지 내려왔으면
			if (x > h) {
				// 정답
				if (y != i)
					return false;
				break;
			}
		}
	}
	return true;
}


void dfs(int x, int cnt, int target_cnt) {
	// 1,2,3번씩 세웠으면
	if (cnt == target_cnt) {
		//canGo();
		if (canGo()) {
			cout << target_cnt;
			exit(0);
		}
		return;
	}

	for (int i = x; i <= h; i++) {
		// y범위 1 줄임
		for (int j = 0; j < n; j++) {
			// 아직 선택되지 않았고 선을 그을 수 있는가
			if (!selected[i][j] && arr[i][j]==0 && arr[i][j+1]==0) {
				arr[i][j] = j + 1;
				arr[i][j + 1] = j;
				selected[i][j] = true;
				dfs(i,cnt + 1, target_cnt);
				selected[i][j] = false;
				arr[i][j + 1] = 0;
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	// 세로 가로
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		// 선을 놓는다.
		// 가로 세로
		arr[a][b] = b + 1;
		arr[a][b + 1] = b;
	}
	// 추가 0개

	if (canGo()) {
		cout << 0;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		memset(selected, false, sizeof(selected));
		// 추가 1개
		dfs(1, 0, i);
	}

	cout << -1;
}