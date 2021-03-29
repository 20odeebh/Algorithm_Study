#include<iostream>
#include<vector>
#include<utility>
#define max_n 50
using namespace std;

int n, m, t;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[max_n + 1][max_n + 1];
vector<pair<int, int>> aircon;
int ans;

void input();
void move_func();
void print();
void solution();
void air_func();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. 먼지 움직이는 함수 구현
	// 2. 공기청정기 함수 구현
	// 3. t초가 지나면, 현재 맵의 먼지갯수 체크
	input();
	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	for (int i = 1; i <= t; ++i)
	{
		move_func();
		air_func();
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == -1) continue;
			ans += map[i][j];
		}
	}
}
void air_func()
{
	int f_x = aircon[0].first; // 위
	int f_y = aircon[0].second; // 
	int s_x = aircon[1].first; // 아래
	int s_y = aircon[1].second;
	
	int temp_map[max_n + 1][max_n + 1] = { 0, };

	temp_map[f_x][f_y] = temp_map[s_x][s_y] = -1;

	// 반시계
	for (int i = f_y + 2; i <= m; ++i) // 왼->오른
	{
		temp_map[f_x][i] = map[f_x][i - 1];
	}
	for (int i = f_x - 1; i >= 1; --i) // 아래 -> 위
	{
		temp_map[i][m] = map[i + 1][m];
	}
	for (int i = m - 1; i >= 1; --i) // 오른 -> 왼
	{
		temp_map[1][i] = map[1][i + 1];
	}
	for (int i = 2; i < f_x; ++i) // 위 -> 아래
	{
		temp_map[i][1] = map[i - 1][1];
	}
	//시계

	for (int i = s_y + 2; i <= m; ++i) // 왼 -> 오른
	{
		temp_map[s_x][i] = map[s_x][i - 1];
	}
	for (int i = s_x + 1; i <= n; ++i) // 위->아래
	{
		temp_map[i][m] = map[i - 1][m]; 
	}
	for (int i = m - 1; i >= 1; --i) // 오른 -> 왼
	{
		temp_map[n][i] = map[n][i + 1];
	}
	for (int i = n - 1; i > s_x; --i) // 아래 -> 위
	{
		temp_map[i][1] = map[i + 1][1];
	}

	// 옮기기

	for (int i = 2; i <= m; ++i)
	{
		map[f_x][i] = temp_map[f_x][i];
	}
	for (int i = f_x; i >= 1; --i)
	{
		map[i][m] = temp_map[i][m];
	}
	for (int i = m; i >= 1; --i)
	{
		map[1][i] = temp_map[1][i];
	}
	for (int i = 1; i < f_x; ++i)
	{
		map[i][1] = temp_map[i][1];
	}

	//

	for (int i = 1; i <= m; ++i)
	{
		map[s_x][i] = temp_map[s_x][i];
	}
	for (int i = s_x; i <= n; ++i)
	{
		map[i][m] = temp_map[i][m];
	}
	for (int i = m; i >= 1; --i)
	{
		map[n][i] = temp_map[n][i];
	}
	for (int i = n; i > s_x; --i)
	{
		map[i][1] = temp_map[i][1];
	}
}
void move_func()
{
	int temp_map[max_n + 1][max_n + 1] = { 0, }; // 흩어지는먼지 저장
	
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int cur_sum = map[i][j];
			if (cur_sum == 0) continue; // 날릴 먼지가 없음
			
			int cur_cnt = 0; // 확산 방향 갯수
			int temp = (cur_sum / 5); // 확산 양

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (map[nx][ny] == -1) continue;

				++cur_cnt;
				temp_map[nx][ny] += temp;
			}
			temp_map[i][j] += map[i][j] - (temp * cur_cnt);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			map[i][j] = temp_map[i][j];
		}
	}
}
void input()
{
	cin >> n >> m >> t;
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1) aircon.push_back({ i,j });
		}
	}
}
void print()
{
	cout << "\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}