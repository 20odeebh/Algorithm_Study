#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>
#include <stack>

using namespace std;

// 한 정점으로부터 다른 모든 정점으로의 최단거리 : 다익스트라 알고리즘
// PQ를 사용해서 최단거리 갱신

int V, E;
int start;
vector<pair<int,int>> edge[20001];
int dist[20001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		dist[i] = INT_MAX;
	cin >> start;
	dist[start] = 0;

	for (int i = 0; i < E; i++) {
		int a, b, w; cin >> a >> b >> w;
		edge[a].push_back({ b,w });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		for (int i = 0; i < edge[node].size(); i++) {
			int next_node = edge[node][i].first;
			int next_dist = edge[node][i].second;
			if (dist[next_node] > cur_dist + next_dist) {
				dist[next_node] = cur_dist + next_dist;
				pq.push({ dist[next_node],next_node });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}

