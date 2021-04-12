#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#define max_n 20
using namespace std;

vector<int> ans;
bool visit[max_n + 1][max_n + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[max_n + 1];
int x, y, n;
int start_cnt;
int cur_max;
int temp_map[max_n + 1][max_n + 1];
int map[max_n + 1][max_n + 1];
vector<int> dfs_v;
void input();
void gravity();
void duplicate();
void print();
void solution();
void dfs(int depth, int cur);
void bfs(int selected_y);
int get_temp_cnt();
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
		ans.push_back(cur_max);

		for (int i = 1; i <= max_n; ++i)
		{
			for (int j = 1; j <= max_n; ++j)
			{
				map[i][j] = 0;
			}
		}
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
	cur_max = 20000000;
	dfs(0, 1);// y열중, 1개 선택 y^n
}
void dfs(int depth, int cur)
{
	if (cur_max == 0) return;
	if (depth == n)
	{
		duplicate();
		int v_size = dfs_v.size();

		for (int i = 0; i < v_size; ++i)
		{
			bfs(dfs_v[i]);

			gravity(); // 끝났으면 gravity 호출

		}

		int temp_cnt; // 원래 map과 temp_map의 갯수차이 = 그떄의 답
		temp_cnt = start_cnt - get_temp_cnt();
		cur_max = min(cur_max, start_cnt - temp_cnt);
		return;
	}
	for (int i = cur; i <= y; ++i)
	{
		dfs_v.push_back(i);
		dfs(depth + 1, cur);
		dfs_v.pop_back();
	}
}
int get_temp_cnt()
{
	int res = 0;

	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			if (temp_map[i][j] != 0) ++res;
		}
	}

	return res;
}
void bfs(int selected_y)
{
	// 맨위에 벽돌
	// 맨위에꺼를 시작으로 주위 bfs 시작
	queue<pair<int, int>> q;

	for (int i = 1; i <= x; ++i)
	{
		if (temp_map[i][selected_y] != 0)
		{
			q.push({ i,selected_y });
			break;
		}
	}

	while (1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		int cur_val = temp_map[cur_x][cur_y];
		temp_map[cur_x][cur_y] = 0;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x;
			int ny = cur_y;

			for (int val = 1; val < cur_val; ++val)
			{
				nx += dx[k];
				ny += dy[k];

				if (nx < 1 || nx < 1 || nx > x || ny > y) break;
				if (temp_map[nx][ny] == 0) continue;
				if (temp_map[nx][ny] == 1)
				{
					temp_map[nx][ny] = 0;
					continue;
				}

				q.push({ nx,ny });
			}
		}
	}
}
void print()
{
	cout << "\n\n";
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			cout << temp_map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void gravity()
{
	vector<int> temp;

	for (int i = 1; i <= y; ++i)
	{
		temp.clear();
		for (int j = x; j >= 1; --j)
		{
			if (temp_map[j][i] != 0)
			{
				temp.push_back(temp_map[j][i]);
				temp_map[j][i] = 0;
			}
		}
		int temp_size = temp.size();
		int idx = 0;
		if (temp_size == 0) continue;
		for (int j = x; j >= 1; --j)
		{
			temp_map[j][i] = temp[idx];
			++idx;
			if (idx >= temp_size) break;
		}
	}
}
void duplicate()
{
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			temp_map[i][j] = map[i][j];
		}
	}
}
void input()
{
	start_cnt = 0;
	cin >> n >> y >> x;
	for (int i = 1; i <= x; ++i)
	{
		for (int j = 1; j <= y; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] != 0) ++start_cnt;
		}
	}
}