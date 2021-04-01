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
#include<math.h>

using namespace std;
// 1. 파이어볼 이동
// 2. 2개 이상이 있으면 
     // - 하나로 합치기 
     // - 4개로 나누기 (각각 질량, 속력,방향 지문에 따라 계산)
// 3. 질량이 0인것은 없애기

// 배열에 파이어볼의 방향과 속력 저장(여러개 가능) deque

int n, m, k;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
struct INFO {
	int dir,weight,speed;
};

int same_dir[4] = { 0,2,4,6 };
int diff_dir[4] = { 1,3,5,7 };

vector<INFO> arr[51][51];


void move_balls() {

	deque<INFO> tmp[51][51];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto &k : arr[i][j]) {
				INFO cur = k;
				// 범위 넘어갈 때
				int nx = i + dx[cur.dir] * cur.speed;
				int ny = j + dy[cur.dir] * cur.speed;
				while (nx < 0)
					nx += n;
				while (nx >= n)
					nx -= n;
				while (ny < 0)
					ny += n;
				while (ny >= n)
					ny -= n;
				tmp[nx][ny].push_back({ cur.dir, cur.weight,cur.speed });
			}
			arr[i][j].clear();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j].empty())
				continue;
			if (tmp[i][j].size() == 1) {
				arr[i][j].push_back({ tmp[i][j][0].dir,tmp[i][j][0].weight,tmp[i][j][0].speed });
			}
			else if (tmp[i][j].size() >= 2) {
				// 4개로 나누면 arr에 저장하는건가..?
				int total_weight = 0;
				int total_speed = 0;
				bool even = false;
				bool odd = false;
				int tmp_dir;
				int total_cnt = tmp[i][j].size();

				for (auto &k : tmp[i][j]) {
					total_weight += k.weight;
					total_speed += k.speed;
					if (k.dir % 2 == 0)
						even = true;
					else
						odd = true;
				}
				if (total_weight < 5)
					continue;

				if (even && odd) {
					tmp_dir = 1;
				}
				else {
					tmp_dir = 0;
				}

				// 4개로 나누기 
				for (int k = 0; k < 4; k++) {
					arr[i][j].push_back({ 2 * k + tmp_dir, total_weight / 5,total_speed / total_cnt });
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	// 초기화

	for (int i = 0; i < m; i++) {
		int r, c, m, s, d; 
		cin >> r >> c >> m >> s >> d;
		r--; c--;
		arr[r][c].push_back({ d,m,s });
	}

	while(k--){
		move_balls();
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (auto &k : arr[i][j]) {
				res += k.weight;
			}
		}
	}
	cout << res;

}

