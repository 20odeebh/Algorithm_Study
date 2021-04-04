#include<iostream>
#include<vector>
#define max_n 100000
using namespace std;

vector<int> g[max_n + 1];
int par[max_n + 1];
int n;
void input();
void dfs(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dfs(1);

	for (int i = 2; i <= n; ++i)
	{
		cout << par[i] << '\n';
	}

	return 0;
}
void dfs(int cur)
{
	int cur_size = g[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		if (par[g[cur][i]] == 0)
		{
			par[g[cur][i]] = cur;
			dfs(g[cur][i]);
		}
	}
}
void input()
{
	cin >> n;
	
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}