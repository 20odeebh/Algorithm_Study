#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define max_n 8
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;
vector<int> ans;
int map[max_n + 1][max_n + 1]; // -1벽, 1 바이러스
bool visit[max_n + 1][max_n + 1];
int n, m;
int sx, sy;
void solution();
void spread();
void visit_clear();
void clear_func();
void input();
void print();
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
		cout << '#' << i + 1 << ' ';
		if (ans[i] == -4) cout << "CANNOT ESCAPE\n";
		else if (ans[i] == -1) cout << "ZOMBIE\n";
		else cout << ans[i] << '\n';
	}

	return 0;
}
void clear_func()
{
	while (1)
	{
		if (q.empty()) break;
		q.pop();
	}
	for (int i = 1; i <= max_n; ++i)
	{
		for (int j = 1; j <= max_n; ++j)
		{
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
}
void solution()
{
	spread();

	int res = 10000000;

	int time = 1;
	bool is_escape = false;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	visit_clear();

	while (1)
	{
		int q_size = q.size();
		if (q.empty()) break;

		for (int i = 0; i < q_size; ++i)
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];
				if (nx < 1 || ny < 1 || nx >n || ny > m)
				{
					is_escape = true;
					break;
				}
				if (map[nx][ny] == -1) continue;
				if (map[nx][ny] != 0 && map[nx][ny] <= time + 1) continue;
				if (visit[nx][ny]) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
		if (is_escape) break;
		++time;
	}
	if (is_escape) ans.push_back(time);
	else
	{
		while (1)
		{
			if (q.empty()) break; // 큐 비우기
			q.pop();
		}
		visit_clear();

		q.push({ sx,sy });
		visit[sx][sy] = true;
		is_escape = false;
		bool is_zombie = false;

		while (1)
		{
			int q_size = q.size();
			if (q_size == 0) break;

			for (int i = 0; i < q_size; ++i)
			{
				int cur_x = q.front().first;
				int cur_y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int nx = cur_x + dx[k];
					int ny = cur_y + dy[k];
					if (nx < 1 || ny < 1 || nx >n || ny > m)
					{
						is_escape = true;
						break;
					}
					if (map[nx][ny] == -1) continue;
					if (visit[nx][ny]) continue;
					if (map[nx][ny] != 0 && map[nx][ny] <= time + 1) is_zombie = true;
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
			if (is_escape) break;
		}

		if (is_zombie) ans.push_back(-1);
		else if (is_escape) ans.push_back(-1);
		else ans.push_back(-4);
	}
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void spread()
{
	int time = 2;

	while (1)
	{
		int q_size = q.size();
		if (q_size == 0) break;

		for (int i = 0; i < q_size; ++i)
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];
				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (map[nx][ny] != 0) continue;

				q.push({ nx,ny });
				map[nx][ny] = time;
			}
		}
		++time;
	}
}
void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int num;
			cin >> num;
			if (num == 1) map[i][j] = -1;
			else if (num == 2)
			{
				map[i][j] = 1;
				q.push({ i,j });
			}
			else if (num == 3) { sx = i; sy = j; map[i][j] = 0; }
		}
	}
}