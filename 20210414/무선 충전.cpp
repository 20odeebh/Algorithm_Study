#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#define max_n 10
using namespace std;
typedef struct
{
	int x, y, c, p;
}bc;
vector<int> a;
vector<int> b;
int ax, ay, bx, by;
int n, m;
bc bc_map[max_n + 1];
vector<int> ans;
vector<int> map[max_n + 1][max_n + 1];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
void solution();
void input();
void bfs(int idx);
void print();
void move_func();
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
	a.clear();
	b.clear();
	for (int i = 1; i <= 10; ++i)
	{
		bc_map[i] = { 0,0,0,0 };
		for (int j = 1; j <= 10; ++j)
		{
			map[i][j].clear();
		}
	}
}
void solution()
{
	for (int i = 1; i <= m; ++i)
	{
		bfs(i);
	}
	move_func();
	//print();
}
void move_func()
{
	ax = ay = 1;
	bx = by = 10;
	int a_sum = 0;
	int b_sum = 0;
	if (map[ax][ay].size() != 0)
	{
		int temp_max = 0;
		for (int i = 0; i < map[ax][ay].size(); ++i)
		{
			temp_max = max(temp_max, bc_map[map[ax][ay][i]].p);
		}
		a_sum += temp_max;
	}
	if (map[bx][by].size() != 0)
	{
		int temp_max = 0;
		for (int i = 0; i < map[bx][by].size(); ++i)
		{
			temp_max = max(temp_max, bc_map[map[bx][by][i]].p);
		}
		a_sum += temp_max;
	} // 0초 부터 충전 가능

	//cout << a_sum << ", " << b_sum << '\n';

	for (int i = 0; i < n; ++i)
	{
		ax += dx[a[i]];
		ay += dy[a[i]];
		bx += dx[b[i]];
		by += dy[b[i]];
		//cout << ax << ", " << ay << ", " << bx << ", " << by << '\n';
		int a_idx = -1;
		int b_idx = -1;
		if (map[ax][ay].size() != 0) // 각각의 bc에서 맥스값 찾기
		{
			int temp_max = 0;
			for (int i = 0; i < map[ax][ay].size(); ++i)
			{
				int cur_idx = map[ax][ay][i];
				if (temp_max < bc_map[cur_idx].p)
				{
					a_idx = cur_idx;
					temp_max = bc_map[cur_idx].p;
				}
			}
		}
		if (map[bx][by].size() != 0)
		{
			int temp_max = 0;
			for (int i = 0; i < map[bx][by].size(); ++i)
			{
				int cur_idx = map[bx][by][i];
				if (temp_max < bc_map[cur_idx].p)
				{
					b_idx = cur_idx;
					temp_max = bc_map[cur_idx].p;
				}
			}
		}
		if (a_idx != -1 && b_idx != -1) // bc가 겹칠수도 있는 경우 
		{
			if (a_idx != b_idx) // 안겹치는 경우
			{
				a_sum += bc_map[a_idx].p;
				b_sum += bc_map[b_idx].p;
			}
			else // bc가 겹치는 경우
			{
				if (map[ax][ay].size() == 1 && map[bx][by].size() == 1) // 서로 하나만 있는 경우
				{
					a_sum += (bc_map[a_idx].p / 2);
					b_sum += (bc_map[b_idx].p / 2);
				}
				else if (map[ax][ay].size() == 1) // a가 하나만 있는 경우 b의 두번쨰 맥스값 찾기
				{
					int b_size = map[bx][by].size();
					int second_max = 0;
					for (int k = 0; k < b_size; ++k)
					{
						if (bc_map[map[bx][by][k]].p == bc_map[a_idx].p) continue;
						second_max = max(bc_map[map[bx][by][k]].p, second_max);
					}
					a_sum += bc_map[a_idx].p;
					b_sum += second_max;
				}
				else if (map[bx][by].size() == 1) // b가 하나만 있는 경우
				{
					int a_size = map[ax][ay].size();
					int second_max = 0;
					for (int k = 0; k < a_size; ++k)
					{
						if (bc_map[map[ax][ay][k]].p == bc_map[b_idx].p) continue;
						second_max = max(bc_map[map[ax][ay][k]].p, second_max);
					}
					a_sum += second_max;
					b_sum += bc_map[b_idx].p;
				}
				else // 서로 여러개 중 맥스값이 같은 idx인 경우
				{
					int second_max = 0;
					int cur_max = bc_map[b_idx].p;

					int a_size = map[ax][ay].size();
					for (int k = 0; k < a_size; ++k)
					{
						if (bc_map[map[ax][ay][k]].p == cur_max) continue;
						second_max = max(bc_map[map[ax][ay][k]].p, second_max);
					}
					int b_size = map[bx][by].size();
					for (int k = 0; k < b_size; ++k)
					{
						if (bc_map[map[bx][by][k]].p == cur_max) continue;
						second_max = max(bc_map[map[bx][by][k]].p, second_max);
					}

					a_sum += cur_max;
					b_sum += second_max;

				}
			}
		}
		else // bc가 겹칠일이 없는 경우
		{
			if (a_idx != -1) a_sum += bc_map[a_idx].p;
			if (b_idx != -1) b_sum += bc_map[b_idx].p;
		}
		//cout << a_sum << ", " << b_sum << '\n';
	}

	ans.push_back(a_sum + b_sum);
}
void print()
{
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			cout << map[i][j].size() << ' ';
		}
		cout << '\n';
	}
}
void bfs(int idx)
{
	bc cur = bc_map[idx];
	bool visit[max_n + 1][max_n + 1] = { false, };
	visit[cur.x][cur.y] = true;
	map[cur.x][cur.y].push_back(idx);
	queue<pair<int, int>> q;
	q.push({ cur.x, cur.y });
	
	int cur_len = cur.c;

	for (int i = 0; i < cur_len; ++i)
	{
		int q_size = q.size();
		for (int j = 0; j < q_size; ++j)
		{
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int k = 1; k <= 4; ++k)
			{
				int nx = dx[k] + cur_x;
				int ny = dy[k] + cur_y;

				if (nx < 1 || ny < 1 || nx > 10 || ny > 10) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = true;
				map[nx][ny].push_back(idx);
				q.push({ nx,ny });
			}
		}
	}

	while (1)
	{
		if (q.empty()) break;
		q.pop();
	}
	
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		b.push_back(num);
	}
	for (int i = 1; i <= m; ++i)
	{
		int x, y, c, p;
		cin >> y >> x >> c >> p;
		bc_map[i] = { x,y,c,p };
	}
}