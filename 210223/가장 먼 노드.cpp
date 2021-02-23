#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX_SIZE 20001
int visit[MAX_SIZE];
vector<int> graph[MAX_SIZE];
int max_dist = 0;
void bfs(int n)
{
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visit[n] = 1;
	while (!q.empty()) {
		int cur, dist;
		cur = q.front().first;
		dist = q.front().second;
		q.pop();
		for (const auto& next : graph[cur]) {
			if (visit[next] == 0) {
				visit[next] = dist + 1;
				q.push({ next, dist + 1 });
				max_dist = max(dist + 1, max_dist);
			}
		}
	}
}
void make_graph(int n, vector<vector<int>>& edge)
{
	for (const auto& e : edge) {
		graph[e[0]].push_back(e[1]);
		graph[e[1]].push_back(e[0]);
	}
}
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	make_graph(n, edge);
	bfs(1);
	for (int i = 2; i <= n; i++)
		answer = max_dist == visit[i] ? answer + 1 : answer;

	return answer;
}