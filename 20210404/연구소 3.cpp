#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
#define max_n 50
#define max_m 10
#define INF 2000000000
using namespace std;

int N, M;
bool check[max_m + 1];
vector<pair<int, int>> virus;
int v_size;
int map[max_n + 1][max_n + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visit[max_n + 1][max_n + 1];
queue<pair<int, int>> q;
int ans;
int empty_cnt;
void input();
void solution();
void dfs(int depth, int cur);
void visit_clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	if (empty_cnt == 0) cout << 0 << '\n';
	else
	{
		solution();
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}
void solution()
{
	v_size = virus.size();
	ans = INF;
	dfs(0, 0);
}
void bfs()
{
	int cnt = 0;
	int time = 0;

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
				int nx = dx[k] + cur_x;
				int ny = dy[k] + cur_y;

				if (map[nx][ny] == 1)continue;
				if (visit[nx][ny]) continue;
				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

				if (map[nx][ny] == 0) ++cnt;
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
		++time;
		if (cnt == empty_cnt)
		{
			ans = min(time, ans);
			break;
		}
	}
	while (1)
	{
		if (q.empty()) break;
		q.pop();
	}
	//cout << cnt << ", " << empty_cnt << '\n';
}
void dfs(int depth, int cur)
{
	if (depth == M)
	{
		visit_clear();
		for (int i = 0; i < v_size; ++i)
		{
			if (check[i])
			{
				q.push({ virus[i].first,virus[i].second });
				visit[virus[i].first][virus[i].second] = true;
			}
		}
		bfs();

		return;
	}
	for (int i = cur; i < v_size; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(depth + 1, i);
			check[i] = false;
		}
	}
}
void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) ++empty_cnt;
			if (map[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}
}
void visit_clear()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			visit[i][j] = false;
		}
	}
}