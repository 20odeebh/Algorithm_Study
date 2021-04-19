#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define max_n 15
#define INF 999999999
using namespace std;

typedef struct
{
	int x, y, cnt;
}swim;
vector<int> ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[3][max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int n;
int sx, sy;
int ex, ey;
void input();
void solution();
void bfs();
void clear_func();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		input();
		solution();
		clear_func();
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}
void clear_func()
{
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			map[0][i][j] = 0;
			map[1][i][j] = 0;
			map[2][i][j] = 0;

			visit[i][j] = false;
		}
	}
}
void solution()
{
	bfs();
}
void bfs()
{
	queue<swim> q;
	q.push({ sx,sy,0 });

	visit[sx][sy] = true;
	int res = INF;

	while (1)
	{
		if (q.empty()) break;

		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_cnt = q.front().cnt;
		q.pop();

		if (cur_x == ex && cur_y == ey)
		{
			res = min(res, cur_cnt);
		}

		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x + dx[k];
			int ny = cur_y + dy[k];

			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visit[nx][ny]) continue;
			if (map[cur_cnt%3][nx][ny] == 1) continue;
			if (map[cur_cnt % 3][nx][ny] == 2)
			{
				q.push({ cur_x,cur_y,cur_cnt+1});
			}
			else
			{
				visit[nx][ny] = true;
				q.push({ nx,ny,cur_cnt + 1 });
			}
				
			
		}
	}
	
	if (res == INF) ans.push_back(-1);
	else ans.push_back(res);
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int num;
			cin >> num;
			if (num == 2)
			{
				map[0][i][j] = 2;
				map[1][i][j] = 2;
				map[2][i][j] = 0;
			}
			else
			{
				map[0][i][j] = num;
				map[1][i][j] = num;
				map[2][i][j] = num;
			}
		}
	}
	cin >> sx >> sy >> ex >> ey;

	++sx; ++sy; ++ex; ++ey;
}