#include<bits/stdc++.h>

using namespace std;

int V, E, K, u, v, w;
int weight, node, next_weight, next_node, ans[20001];

vector<pair<int, int>> vec[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++) {
		ans[i] = 1000000000;
	}

	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;
		vec[u].push_back(pair<int, int>(v, w));
	}

	ans[K] = 0;
	pq.push(make_pair(0, K)); 

	while (!pq.empty())
	{
		weight = pq.top().first;
		node = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[node].size(); i++){
			next_node = vec[node][i].first;
			next_weight = weight + vec[node][i].second;
			if (ans[next_node] > next_weight)
			{
				ans[next_node] = next_weight;
				pq.push(make_pair(next_weight, next_node));
			}
		}
	}

	for (int i = 1; i <= V; i++){
		if (ans[i] == 1000000000) cout << "INF" << '\n';
		else cout << ans[i] << '\n';
	}
}
