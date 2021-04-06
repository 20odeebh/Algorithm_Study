#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define max_n 12
using namespace std;

typedef struct
{
	int x, y, move;
}horse;
int horse_cnt;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int paper[max_n + 1][max_n + 1]; // 체스판
vector<pair<int, int>> map[max_n + 1][max_n + 1]; // 현재 누적 말갯수 저장
int ans;
int n;
horse horse_location[max_n + 1]; // 각 인덱스별 맵에서의 위치, 움직이는 방향 저장
void input();
void solution();
int get_idx(int x, int y, int cur_horse);
int get_oppsite(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	if (ans >= 1001) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
void solution()
{
	// map vector의 사이즈에서, 현재 위치 찾기
	// 현재 위치부터, 끝 번호까지 임시 vector에 옮기고, 기존 map의 vector 삭제
	// 갈 곳의 바닥 색깔 확인
	// 흰 : map vector에 임시 vector 옮기기
	// 빨 : 뒤집고 옮기기
	// 파 or 범위초과 : move를 뒤로하고 한칸 이동 만약 바꿨어도 파or범위초과이면 중지
	// 각 말들이 움직인 후, horse_location 수정
	// 움직인 공간의 사이즈가 4이상이다 -> 종료

	bool check = false;
	while (1)
	{
		if (ans > 1000) break;

		for (int i = 1; i <= horse_cnt; ++i)
		{
			int cur_x, cur_y, cur_move;
			cur_x = horse_location[i].x;
			cur_y = horse_location[i].y;
			cur_move = horse_location[i].move;

			int cur_idx = get_idx(cur_x, cur_y, i);
			int map_size = map[cur_x][cur_y].size();

			int nx = cur_x + dx[cur_move];
			int ny = cur_y + dy[cur_move];
			int next_color;

			if (nx < 1 || ny < 1 || nx > n || ny > n) next_color = 2; // 범위초과는 파랑색이랑 같음
			else next_color = paper[nx][ny];

			if (next_color == 2)
			{
				cur_move = get_oppsite(cur_move);
				nx = cur_x + dx[cur_move];
				ny = cur_y + dy[cur_move];

				if (nx < 1 || ny < 1 || nx > n || ny > n) next_color = 2;
				else next_color = paper[nx][ny];

				if (next_color == 2)
				{
					map[cur_x][cur_y][cur_idx].second = cur_move;
					continue;
				}
			}

			map[cur_x][cur_y][cur_idx].second = cur_move;

			vector<pair<int, int>> temp;

			for (int j = cur_idx; j < map_size; ++j) temp.push_back(map[cur_x][cur_y][j]); // 현재위치에서 위에것들 가져오기
			map[cur_x][cur_y].erase(map[cur_x][cur_y].begin() + cur_idx, map[cur_x][cur_y].end()); // 현위치~위에거 기존 맵에서 삭제

			int temp_size = temp.size();

			if (next_color == 1) reverse(temp.begin(), temp.end()); // 빨강이면 뒤집기

			for (int k = 0; k < temp_size; ++k)
			{
				map[nx][ny].push_back(temp[k]); // 다음위치에 옮겨주기
				horse_location[temp[k].first] = { nx,ny,temp[k].second }; // 말 정보에 현재위치 수정
			}
			temp.clear();

			if (map[nx][ny].size() >= 4) // 종료조건
			{
				check = true;
				break;
			}
		}
		++ans;
		if (check) break;
	}
}
int get_oppsite(int cur)
{
	if (cur == 1) return 2;
	else if (cur == 2) return 1;
	else if (cur == 3) return 4;
	else if (cur == 4) return 3;
}
int get_idx(int x, int y, int cur_horse)
{
	int cur_idx = 0;
	int map_size = map[x][y].size();
	for (int j = 0; j < map_size; ++j)
	{
		if (map[x][y][j].first == cur_horse)
		{
			cur_idx = j;
			break;
		}
	}
	return cur_idx;
}
void input()
{
	cin >> n >> horse_cnt;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> paper[i][j];
		}
	}
	for (int i = 1; i <= horse_cnt; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		horse_location[i].x = a;
		horse_location[i].y = b;
		horse_location[i].move = c;
		map[a][b].push_back({ i,c }); // map에 각 좌표의 말들 추가 pair<번호, 방향>
	}
}