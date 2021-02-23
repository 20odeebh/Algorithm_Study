#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define MAX_SIZE 100
int graph[MAX_SIZE][MAX_SIZE];
int set[MAX_SIZE];
int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}
int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	priority_queue<pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> pq;
	for (const auto& cost : costs)
		pq.push({ cost[2],{ cost[0], cost[1] } });
	for (int i = 0; i < n; i++)
		set[i] = i;

	while (!pq.empty()) {
		int s, e, d;
		s = pq.top().second.first;
		e = pq.top().second.second;
		d = pq.top().first;
		pq.pop();
		if (!find(set, s, e)) {
			answer += d;
			unionParent(set, s, e);
		}
	}
	return answer;
}