#include<iostream>
#include<vector>
#define max_n 100
using namespace std;

int n;
bool visit[max_n + 1][max_n + 1];
int map[max_n + 1][max_n + 1];
vector<int> g[max_n + 1];
void input();
void dfs(int cur, int next);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// ������� ���� -> ����Ʈ���·� ����
	// dfs�� ����, visitüũ, ����Ⱥκ� ������� ����

	input();

	for (int i = 1; i <= n; ++i) // ������ ��忡�� ����Ⱥκ� ������ Ÿ�� ����
	{
		int g_size = g[i].size();
		for (int k = 0; k < g_size; ++k)
		{
			dfs(i, g[i][k]);
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
void dfs(int cur, int next)
{
	if (visit[cur][next]) return; // �̹� ���� ��θ�

	int next_size;
	next_size = g[next].size();

	visit[cur][next] = true;
	map[cur][next] = 1;

	for (int k = 0; k < next_size; ++k)
	{
		dfs(cur, g[next][k]);
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
			if (map[i][j] == 1)
			{
				g[i].push_back(j); // ����� �κ� ����
			}
		}
	}
}