#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define max_n 20
using namespace std;

int N, M;
int ans;
vector<int> ans_v;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int get_cost(int num);
void visit_clear();
void map_clear();
void bfs(int x, int y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				cin >> map[i][j];
			}
		}
		// 최대한 늘려 적자가 나지 않는 한에서 많은집 케어할 수 있게

		// 0, 1 지점마다 늘려보기 ? -> 몇까지 ?
		ans = 0;
		visit_clear();
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				visit_clear();
				bfs(i, j);
			}
		}

		ans_v.push_back(ans);

		map_clear();
	}

	for (int i = 0; i < T; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans_v[i] << '\n';
	}

	return 0;
}
void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	int depth = 1;
	visit[x][y] = true;
	int home_cnt = 0;
	if (map[x][y] == 1) ++home_cnt;
	while (1)
	{
		if (q.empty()) break;
		if (depth > N + 1) break;

		if (home_cnt * M >= get_cost(depth))
		{
			ans = home_cnt > ans ? home_cnt : ans;
		}

		int q_size = q.size();

		for (int k = 0; k < q_size; ++k)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (visit[nx][ny]) continue;
				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;

				if (map[nx][ny] == 1) ++home_cnt;

				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
		++depth;
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
void map_clear()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = 0;
		}
	}
}
int get_cost(int num)
{
	return num * num + (num - 1)*(num - 1);
}