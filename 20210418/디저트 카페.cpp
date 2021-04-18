#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 20
#define max_d 100
using namespace std;

vector<int> ans;
int dx[4] = { 1,-1,-1,1 };
int dy[4] = { 1,1,-1,-1 };
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
bool eaten[max_d + 1];
int n;
int cnt;
void input();
void visit_clear();
void solution();
void dfs(int depth, int sx, int sy, int cur_x, int cur_y, int cur_move);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		input();
		solution();
		if (cnt == 0)ans.push_back(-1);
		else ans.push_back(cnt);
	}

	int ans_size = ans.size();
	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}
	return 0;
}
void solution()
{
	cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dfs(0, i, j, i, j, 0);
		}
	}
}
void dfs(int depth, int sx, int sy, int cur_x, int cur_y, int cur_move)
{
	if (sx == 3 && sy == 1)
	{
		//	cout << cur_x << ", " << cur_y << '\n';
	}
	if (depth != 0 && sx == cur_x && sy == cur_y)
	{
		cnt = max(depth, cnt);
		return;
	}

	int nx = cur_x + dx[cur_move];
	int ny = cur_y + dy[cur_move];
	if ((nx >= 1 && ny >= 1 && nx <= n && ny <= n) && visit[nx][ny] == false && eaten[map[nx][ny]] == false) // 그방향 그대로
	{
		visit[nx][ny] = true;
		eaten[map[nx][ny]] = true;
		dfs(depth + 1, sx, sy, nx, ny, cur_move);
		visit[nx][ny] = false;
		eaten[map[nx][ny]] = false;
	}
	if (cur_move < 3)
	{
		int nx = cur_x + dx[cur_move + 1];
		int ny = cur_y + dy[cur_move + 1];
		if ((nx >= 1 && ny >= 1 && nx <= n && ny <= n) && visit[nx][ny] == false && eaten[map[nx][ny]] == false) // 꺾기
		{
			visit[nx][ny] = true;
			eaten[map[nx][ny]] = true;
			dfs(depth + 1, sx, sy, nx, ny, cur_move + 1);
			visit[nx][ny] = false;
			eaten[map[nx][ny]] = false;
		}
		else return;
	}
	return;
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}