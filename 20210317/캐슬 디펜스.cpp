#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>
#define INF 99999999
#define max_n 15
using namespace std;

int ans;
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int use_map[max_n + 1][max_n + 1];
bool check[max_n + 1];
vector<pair<int, int>> h;
vector<pair<int, int>> e;
int n, m, d;
void init();
void down();
void comb(int cur, int depth);
void solution();
void dupli();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	comb(1, 0);

	cout << ans << '\n';

	return 0;
}
void solution() //use_map
{

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (use_map[i][j] == 1) e.push_back({ i,j });
		}
	}

	int h_size = h.size();
	int e_size = e.size();

	for (int i = 0; i < h_size; ++i)
	{
		int cur_x = h[i].first;
		int cur_y = h[i].second;
		int cur_dis = INF;
		int t_x = -1;
		int t_y = -1;

		for (int j = 0; j < e_size; ++j)
		{
			int e_x = e[j].first;
			int e_y = e[j].second;

			int temp_dis = abs(cur_x - e_x) + abs(cur_y - e_y);

			if (temp_dis > d) continue;

			if (cur_dis == temp_dis)
			{
				if (t_y < e_y) continue;
				t_x = e_x;
				t_y = e_y;
			}
			else if (cur_dis > temp_dis)
			{
				t_x = e_x;
				t_y = e_y;
				cur_dis = temp_dis;
			}
		}
		if (t_x != -1 && t_y != -1) visit[t_x][t_y] = true;
	}

	e.clear();
}
void comb(int cur, int depth) // mC3
{
	if (depth == 3)
	{
		int res = 0;
		for (int i = 1; i <= m; ++i)
		{
			if (check[i])
			{
				h.push_back({ n + 1, i });
			}
		}

		dupli();

		for (int k = 1; k <= n; ++k)
		{
			solution();
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= m; ++j)
				{
					if (visit[i][j])
					{
						++res;
						use_map[i][j] = 0;
					}
					visit[i][j] = false;
				}
			}
			down();
		}
		ans = max(res, ans);
		h.clear();

		return;
	}
	for (int i = cur; i <= m; ++i)
	{
		if (check[i] == false)
		{
			check[i] = true;
			comb(i, depth + 1);
			check[i] = false;
		}
	}
}
void dupli()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			use_map[i][j] = map[i][j];
		}
	}
}
void init()
{
	cin >> n >> m >> d;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}
void down()
{
	for (int i = n; i >= 1; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			use_map[i][j] = use_map[i - 1][j];
		}
	}
}