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
int arr[5][5];
//모든 경우의 수 진행하기 ,,, ㅜ
char color[10][4][4];
int val[10][4][4];
int n;
vector<int> tmp;
bool visited[10] = { false, };
vector<int> res;
int total = 0;
int dx[4] = { 0,1,0,1 };
int dy[4] = { 0,0,1,1 };
char tmp_color[5][5];
int tmp_val[5][5];

struct INFO {
	int idx, dir, start;
};
vector<INFO> v;

void initTmp() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp_val[i][j] = 0;
			tmp_color[i][j] = 'W';
		}
	}
}

int cal() {
	int r = 0;
	int g = 0;
	int b = 0;
	int y = 0;
	int tmp_total = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (tmp_color[i][j] == 'R') {
				r += tmp_val[i][j];
			}
			else if (tmp_color[i][j] == 'G') {
				g += tmp_val[i][j];
			}
			else if (tmp_color[i][j] == 'B') {
				b += tmp_val[i][j];
			}
			else if (tmp_color[i][j] == 'Y') {
				y += tmp_val[i][j];
			}
		}
	}
	tmp_total = 7 * r + 5 * b + 3 * g + 2 * y;
	return tmp_total;
}

void cal_start(int cnt) {
	// 계산
	if (cnt == 3) {
		initTmp();
		for (auto &k : v) {
			int idx = k.idx;
			int dir = k.dir;
			int start = k.start;
			//cout << idx << ' ' << dir << ' ' << start << endl;

			char dir_color[4][4];
			int dir_val[4][4];
			int sx = dx[start];
			int sy = dy[start];

			if (dir == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						dir_color[i][j] = color[idx][i][j];
						dir_val[i][j] = val[idx][i][j];
					}
				}
			}
			// 오른쪽으로 90도 회전
			else if (dir == 1) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						dir_color[i][j] = color[idx][j][3 - i];
						dir_val[i][j] = val[idx][j][3 - i];
					}
				}
			}
			else if (dir == 2) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						dir_color[i][j] = color[idx][3 - i][3 - j];
						dir_val[i][j] = val[idx][3 - i][3 - j];
					}
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						dir_color[i][j] = color[idx][3 - j][i];
						dir_val[i][j] = val[idx][3 - j][i];
					}
				}
			}
			// 각각 처리 
			// !!! 여기서 실수 !!!!
			// 시작점은 tmp에서만 처리해야한다.
			for (int i = 0; i <  4; i++) {
				for (int j = 0 ; j <  4; j++) {
					tmp_val[i+sx][j+sy] += dir_val[i][j];
					if (tmp_val[i + sx][j + sy] < 0)
						tmp_val[i + sx][j + sy] = 0;
					if (tmp_val[i + sx][j + sy] > 9)
						tmp_val[i + sx][j + sy] = 9;

					if (dir_color[i][j] != 'W')
						tmp_color[i + sx][j + sy] = dir_color[i][j];
				}
			}
		}
		int cal_val = cal();
		//cout << cal_val << endl;
		total = max(cal_val, total);
		return;
	}
	// 3개 뽑은 것들의 방향과 시작 방향 모두 다르게 경우의 수 진행
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			v.push_back({ res[cnt],i,j });
			cal_start(cnt + 1);
			v.pop_back();
		}
	}
}

// 순열로 3개 뽑기
void select(int cnt) {
	if (cnt == 3) {
		cal_start(0);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res.push_back(i);
			select(cnt + 1);
			res.pop_back();
			visited[i] = false;
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int k = 0; k < n; k++) {
		tmp.push_back(k);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cin >> val[k][i][j];
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cin >> color[k][i][j];
		}
	}

	// 주어진 재료 중 3개 고르기 (순서 구분)

	select(0);

	cout << total;
}
