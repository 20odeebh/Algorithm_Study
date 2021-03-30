#include<iostream>
#include<vector>
#define max_n 1000
using namespace std;

int n, m;
int ans;
vector<int> g[max_n + 1];
bool visit[max_n + 1];
bool visit_check();
void input();
void solution();
void dfs(int cur_node);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// visit 체크를 통해, dfs가 호출될 때마다 연결요소 갯수 1개 추가
	
	input();
	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!visit[i])
		{
			++ans;
			dfs(i);
		}
	}
}
void dfs(int cur_node)
{
	int cur_size = g[cur_node].size();
	visit[cur_node] = true;

	for(int i = 0; i < cur_size; ++i)
	{
		int next_node = g[cur_node][i];
		if (visit[next_node]) continue;

		dfs(next_node);
	}
}
bool visit_check()
{
	bool res = true;
	for (int i = 1; i <= n; ++i)
	{
		if (!visit[i])
		{
			res = false;
			break;
		}
	}
	return res;
}
void input()
{
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}