#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#define max_n 8
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int ans;
int wall_size, vir_size;
int map[max_n + 1][max_n + 1];
bool check[max_n + 1][max_n + 1];
bool visit[max_n * max_n + 1];
vector<pair<int, int>> wall;
vector<pair<int, int>> vir;
void input();
void comb(int cur, int depth);
void get_ans();
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. �� ���� ��, 3�� �������� �̱� (64c3) -> 5������
	// 2. �ӽú��� �����, ���̷��� bfs
	// 3. 0���� üũ
	// 4. ���� ū 0������ ��

	input();
	comb(0, 0);

	cout << ans << '\n';
	return 0;
}
void solution()
{
	int temp_map[max_n + 1][max_n + 1] = { 0, };
	for (int i = 1; i <= n; ++i) // ���� ����
	{
		for (int j = 1; j <= m; ++j)
		{
			temp_map[i][j] = map[i][j];
			check[i][j] = false; // check �ʱ�ȭ
		}
	}

	for (int i = 0; i < wall_size; ++i)
	{
		if (visit[i])
		{
			map[wall[i].first][wall[i].second] = 1; // �ӽ� �� 3��
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < vir_size; ++i) // ���̷��� q�� �ֱ�
	{
		int x = vir[i].first;
		int y = vir[i].second;
		q.push({ x,y });
		check[x][y] = true; // bfs ���ʿ��� Ž�� ����
	}

	while (1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x + dx[k];
			int ny = cur_y + dy[k];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (check[nx][ny]) continue;
			if (map[nx][ny] == 1 || map[nx][ny] == 2) continue;

			check[nx][ny] = true;
			map[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}

	get_ans(); // 0���� üũ

	for (int i = 1; i <= n; ++i) // �������
	{
		for (int j = 1; j <= m; ++j)
		{
			map[i][j] = temp_map[i][j];
		}
	}
}
void print()
{
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void get_ans()
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == 0) ++res;
		}
	}

	ans = max(res, ans);
}
void comb(int cur, int depth)
{
	if (depth == 3)
	{
		solution(); // bfs
		return;
	}
	for (int i = cur; i < wall_size; ++i)
	{
		if (!visit[i])
		{
			visit[i] = true;
			comb(i, depth + 1);
			visit[i] = false;
		}
	}
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) vir.push_back({ i,j });
			else if (map[i][j] == 0) wall.push_back({ i,j });
		}
	}
	wall_size = wall.size();
	vir_size = vir.size();
}