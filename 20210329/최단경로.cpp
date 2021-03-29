#include<iostream>
#include<vector>
#include<queue>
#define max_v 20000
#define INF 999999999
using namespace std;
int s, v, e;
int ans[max_v + 1];
vector<pair<int, int>> g[max_v + 1];
void input();
void solution();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 다익스트라
	input();
	
	solution();

	for (int i = 1; i <= v; ++i)
	{
		if (ans[i] == INF) cout << "INF" << '\n';
		else cout << ans[i] << '\n';
	}

	return 0;
}
void solution()
{
	for (int i = 1; i <= v; ++i) ans[i] = INF; // 전체 노드 INF

	ans[s] = 0; // 시작점 0
	
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,s });

	while (1)
	{
		if (pq.empty()) break;

		int cur_node = pq.top().second;
		int cur_dis = -pq.top().first;
		int cur_size = g[cur_node].size();
		pq.pop();

		if (cur_dis > ans[cur_node]) continue;

		for (int i = 0; i < cur_size; ++i)
		{
			int next_node = g[cur_node][i].first;
			int next_dis = g[cur_node][i].second;
			int sum_dis = cur_dis + next_dis;

			if (sum_dis < ans[next_node])
			{
				ans[next_node] = sum_dis;
				pq.push({ -sum_dis, next_node });
			}
		}
	}
}
void input()
{
	cin >> v >> e >> s;
	
	for (int i = 1; i <= e; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
}