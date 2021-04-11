#include<iostream>
#include<utility>
#include<vector>
#define max_n 100
using namespace std;

vector<int> g[max_n + 1];
bool visit[max_n + 1][max_n + 1];
int n;
int s, e;
int t;
int ans;
void input();
void solution(int depth, int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solution(0, s);

	if (ans == 0)cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
void solution(int depth, int cur)
{
	if (cur == e)
	{
		ans = depth;
		return;
	}
	int cur_size = g[cur].size();
	for (int i = 0; i < cur_size; ++i)
	{
		if (visit[cur][g[cur][i]] == false)
		{
			visit[cur][g[cur][i]] = true;
			visit[g[cur][i]][cur] = true;
			solution(depth + 1, g[cur][i]);
		}
	}
}
void input()
{
	cin >> n;
	cin >> s >> e;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}