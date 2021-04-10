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
// 6시

// 위 아래 왼쪽 오른쪽
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
// 각 칸마다, 물고기 번호, 냄새 번호, 냄새 카운트 저장
struct INFO {
	int smell, time;
};
struct FISH {
	int num, x, y, dir;
};

INFO arr[21][21] = { 0, };
vector<FISH> fish;
int res = 0;
int n, m, k;
int priority[401][4][4];


void print_arr() {

	cout << "상어 상태 \n";

	for (auto &k : fish) {
		cout << k.num << "이 " << k.x << ' ' << k.y << ' ' << k.dir << endl;
	}

	cout << "배열 상태 \n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j].smell << ' ';
		}
		cout << endl;
	}

	cout << "시간 \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j].time << ' ';
		}
		cout << endl;
	}

}

bool cmp(FISH f1, FISH f2) {
	return f1.num < f2.num;
}


void spread_smell() {
	for (int i = 0; i < fish.size(); i++) {
		FISH cur = fish[i];
		arr[cur.x][cur.y].smell = cur.num;
		arr[cur.x][cur.y].time = k;
	}

	return;

}

bool IsRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return true;
	return false;
}

void move_shark() {
	// 번호, 방향
	int tmp[21][21][2] = { 0, };

	for (int i = 0; i < fish.size(); i++) {
		// i번째 fish 움직이기
		FISH cur = fish[i];
		bool canGo = false;
		for (int k = 0; k < 4; k++) {
			int ndir = priority[cur.num][cur.dir][k];
			int nx = cur.x + dx[ndir];
			int ny = cur.y + dy[ndir];
			// 비어있으면 끝
			if (IsRange(nx,ny) && arr[nx][ny].smell == 0) {
				// 만약 이미 누가 있으면 .. ?!?
				// 내가 번호 더 작으면 나 없애고,, 내가 번호 더 크면 그 고기 없애기
				canGo = true;
				if (tmp[nx][ny][0]==0 || (tmp[nx][ny][0] != 0 && tmp[nx][ny][0] > cur.num)) {
					tmp[nx][ny][0] = cur.num;
					tmp[nx][ny][1] = ndir;
				}
				break;
			}
		}
		// 비어있는 곳이 없다면 나의 냄새가 있는 곳에 바로 넣기
		if (!canGo) {
			for (int k = 0; k < 4; k++) {
				int ndir = priority[cur.num][cur.dir][k];
				int nx = cur.x + dx[ndir];
				int ny = cur.y + dy[ndir];
				if (IsRange(nx, ny) && arr[nx][ny].smell == cur.num) {
					tmp[nx][ny][0] = cur.num;
					tmp[nx][ny][1] = ndir;
					break;
				}
			}
		}
	}

	fish.clear();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j][0] != 0) {
				fish.push_back({ tmp[i][j][0], i,j,tmp[i][j][1] });
			}
		}
	}

	return;

}

// 시간을 하나씩 줄이고 다 사라지면 냄새 자체 없애기
void down_time() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].time != 0)
			{
				arr[i][j].time--;
				if (arr[i][j].time == 0) {
					arr[i][j].smell = 0;
				}
			}
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	// 인덱스 맞추기 위해

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			if (num != 0) {
				// 일단 dir 0으로 초기화
				fish.push_back({ num,i,j,0 });
				arr[i][j].smell = num;
				arr[i][j].time = k;
			}
		}
	}

	sort(fish.begin(), fish.end(), cmp);

	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		fish[i].dir = num - 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> priority[i][j][k];
				priority[i][j][k] -= 1;
			}
		}
	}

	while (1) {
		res++;
		move_shark();
		down_time();

		spread_smell();

		if (fish.size() == 1) {
			cout << res;
			return 0;
		}

		if (res == 1000)
			break;
	}
	cout << -1;

}
