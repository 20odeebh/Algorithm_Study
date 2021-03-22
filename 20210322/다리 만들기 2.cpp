#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define max_n 10
#define max_g 6
#define INF 999999999
using namespace std;

int N, M;
int map[max_n + 1][max_n + 1];
bool q_visit[max_n + 1][max_n + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int g_cnt;
int ans;

int g[max_g + 1][max_g + 1];
void bfs(int x, int y, int num);
int parents[max_g + 1];
void init();
void Print();
void get_dis();
void dfs(int cur_x, int cur_y, int move_idx, int start_node, int depth);
void solution();
void union_func(int a, int b);
int get_parents(int cur);
bool is_all_clear();
bool find_func(int a, int b);
bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	get_dis();

	solution();

	if (ans == 0) cout << -1 << '\n';
	else cout << ans << '\n';

	//Print();
	return 0;
}
bool is_all_clear()
{
	bool res = true;
	for (int i = 1; i <= g_cnt; ++i) parents[i] = get_parents(i);
	for (int i = 1; i <= g_cnt; ++i)
	{
		if (parents[i] != 1) return false;
	}

	return res;
}
bool find_func(int a, int b)
{
	int pa = get_parents(a);
	int pb = get_parents(b);

	if (pa == pb) return true;
	else return false;
}
void union_func(int a, int b)
{
	int pa = get_parents(a);
	int pb = get_parents(b);

	if (pa < pb) parents[pb] = pa;
	else parents[pa] = pb;
}
int get_parents(int cur)
{
	if (cur == parents[cur]) return cur;

	return parents[cur] = get_parents(parents[cur]);
}
void solution()
{
	vector<pair<pair<int, int>, int>> v;

	for (int i = 1; i <= g_cnt; ++i)
	{
		for (int j = i; j <= g_cnt; ++j)
		{
			if (g[i][j] != INF)
			{
				v.push_back(make_pair(make_pair(i, j), g[i][j]));
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= g_cnt; ++i) parents[i] = i; // 자기자신 부모 셋팅
	int v_size = v.size();

	int cnt = 0;
	for (int i = 0; i < v_size; ++i)
	{
		if (!find_func(v[i].first.first, v[i].first.second)) {
			cnt += v[i].second;
			union_func(v[i].first.first, v[i].first.second);
		}
		if (is_all_clear()) {
			ans = cnt;
			return;
		}
	}
}
void get_dis() // 일정 숫자 발견 시, 한방향 으로만 쭉 직진하다가다른노드 만나면, 깊이와 원래 거리 비교 후, 갱신
{
	for (int k = 0; k < 4; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				if (map[i][j] != 0) dfs(i, j, k, map[i][j], 0);
			}
		}
	}
}
void dfs(int cur_x, int cur_y, int move_idx, int start_node, int depth)
{
	if (map[cur_x][cur_y] != 0 && start_node != map[cur_x][cur_y]) // 0이 아닌데 시작과 다른 경우
	{
		depth -= 1;
		if (g[map[cur_x][cur_y]][start_node] > depth && depth != 1) g[map[cur_x][cur_y]][start_node] = depth;
		return;
	}
	int next_x = cur_x + dx[move_idx];
	int next_y = cur_y + dy[move_idx];

	if (next_x < 1 || next_y < 1 || next_x > N || next_y > M) return; // 범위 초과
	if (map[next_x][next_y] == start_node) return; // 엣지가 아님

	dfs(next_x, next_y, move_idx, start_node, depth + 1);
}
void init()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int num;
			cin >> num;
			if (num == 1) map[i][j] = -1;
		}
	}

	int num = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == -1)
			{
				bfs(i, j, num);
				++num;
			}
		}
	}
	g_cnt = num - 1;

	for (int i = 1; i <= g_cnt; ++i)
	{
		for (int j = 1; j <= g_cnt; ++j)
		{
			g[i][j] = INF;
		}
	}
}
void bfs(int x, int y, int num)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	for (int i = 1; i <= max_n; ++i)
	{
		for (int j = 1; j <= max_n + 1; ++j)
		{
			q_visit[i][j] = false;
		}
	}
	q_visit[x][y] = true;
	map[x][y] = num;

	while (1)
	{
		if (q.empty()) break;

		int cur_x = q.front().first;
		int cur_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = dx[i] + cur_x;
			int ny = dy[i] + cur_y;

			if (nx < 1 || ny < 1 || nx > max_n || ny > max_n) continue;
			if (q_visit[nx][ny]) continue;
			if (map[nx][ny] == 0) continue;

			map[nx][ny] = num;
			q_visit[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
}
void Print()
{
	cout << "\n\n";
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= g_cnt; ++i)
	{
		for (int j = 1; j <= g_cnt; ++j)
		{
			if (g[i][j] == INF) cout << 0 << ' ';
			else  cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
}