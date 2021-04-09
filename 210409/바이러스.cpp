#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 101
vector<int> graph[MAX_SIZE];
int answer = 0;
bool visit[MAX_SIZE];
int N, M;
void dfs(int idx)
{
	if (visit[idx])
		return;
	visit[idx] = true;
	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (visit[next] == false) {
			answer++;
			dfs(next);
		}
	}
}
int main()
{
	cin >> N >> M;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(1);
	printf("%d\n", answer);
	return 0;
}