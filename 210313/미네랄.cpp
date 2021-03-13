#include<cmath>
#include<iostream>
#include <string>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>
#include<functional>
#include<climits>
#include <memory.h>
#include <unordered_set>

using namespace std;
int r, c;
char arr[101][101];
bool checked[101][101] = { false, };
int n;
vector<int> location;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int max_x;

void init() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			checked[i][j] = false;
	}
}

bool IsRange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)
		return true;
	return false;
}

void bfs(int i, int j) {
	queue<pair<int, int>>q;
	q.push({ i,j });
	checked[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsRange(nx,ny) && !checked[nx][ny] && arr[nx][ny] == 'x') {
				q.push({ nx,ny });
				checked[nx][ny] = true;
			}
		}
	}

}

int cal_move(int x, int y) {
	// x,y에서 밑바닥, 혹은 x가 나오기 전까지 칸 수 계산
	int nx = x;
	while (1) {
		// 다음 갈 칸이 막혀있거나 끝나면 멈추기
		if (nx+1 == r || (nx +1<r && arr[nx + 1][y] == 'x'))
			break;
		nx++;
	}
	return nx-x;
}

void print_Arr() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << arr[i][j];
		cout << endl;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str; cin >> str;
		for (int j = 0; j < c; j++)
			arr[i][j] = str[j];
	}
	cin >> n;

	while (n--) {
		int tmpr; cin >> tmpr;
		location.push_back(tmpr);
	}

	for (int i = 0; i < location.size(); i++) {
		int nr = location[i];
		nr = r - nr;
		if (i % 2 == 0) {
			for (int j = 0; j < c; j++) {
				// 미네랄이면 바꿔주기
				if (arr[nr][j] == 'x') {
					arr[nr][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = c; j >= 0; j--) {
				// 미네랄이면 바꿔주기
				if (arr[nr][j] == 'x') {
					arr[nr][j] = '.';
					break;
				}
			}
		}
		// 없애기
		init();
		for (int y = 0; y < c; y++) {
			if (arr[r - 1][y] == 'x') {
				bfs(r - 1, y);
			}
		}
		// 땅에 붙어있지 않은 클러스터는 모양을 유지한채로 내려야한다.
		int move_cnt = 201;
		bool flag = false;
		vector<pair<int, int>> cluster;
		for (int x = r - 2; x >= 0; x--) {
			for (int y = 0; y < c; y++) {
				if (!checked[x][y] && arr[x][y] == 'x') {
					// 움직일 부분이 있다는 뜻
					cluster.push_back({ x,y });
					arr[x][y] = '.';
					flag = true;
					move_cnt = min(cal_move(x, y), move_cnt);
				}
			}
			// x행에 있는 수들 모두 move_cnt만큼 내리자
		}
		for (auto &k : cluster) {
			int x = k.first;
			int y = k.second;
			arr[x + move_cnt][y] = 'x';
			arr[x][y] = '.';
		}
	}
	print_Arr();

}

