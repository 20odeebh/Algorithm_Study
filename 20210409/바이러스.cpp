#include<iostream>
#include<vector>
#include<utility>
#define max_n 100
using namespace std;

vector<int> g[max_n + 1];
bool visit[max_n + 1];
int ans;
int n, v;
void input();
void dfs(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	visit[1] = true;
	dfs(1);

	for (int i = 2; i <= n; ++i) if (visit[i]) ++ans;

	cout << ans << '\n';

	return 0;
}
void dfs(int cur)
{
	int cur_size = g[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		int next_node = g[cur][i];
		if (visit[next_node]) continue;
		visit[next_node] = true;
		dfs(next_node);
	}
}
void input()
{
	cin >> n >> v;
	for (int i = 1; i <= v; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}