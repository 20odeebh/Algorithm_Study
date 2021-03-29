#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <string.h>
#define INF 999988887
using namespace std;
void path(int *arr, int index) {
	if (arr[index] == 0 || arr[index] == -1) {
		cout << index;
		return;
	}
	else
		path(arr, arr[index]);
	cout << " -> " << index;
}
int main()
{
	vector<pair<int, int> > *adj = 0;
	int numofV, numofE, startV;
	cin >> numofV;
	cin >> numofE;
	cin >> startV;

	adj = new vector<pair<int, int> >[numofV + 1];
	for (int i = 0; i < numofE; i++) {
		int start, end, cost;
		cin >> start;
		cin >> end;
		cin >> cost;
		adj[start].push_back(make_pair(end, cost));
	}
	int *visited = new int[numofV + 1];				
	int *dist = new int[numofV + 1];
	for (int i = 0; i <= numofV; i++) visited[i] = -1;	
	for (int i = 0; i <= numofV; i++) dist[i] = INF;

	dist[startV] = 0;
	visited[startV] = 0;

	priority_queue<pair<int, int> > pq;			
												
	pq.push(make_pair(0, startV));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;		
		pq.pop();

		if (dist[cur] < cost) continue;					

		for (int i = 0; i < adj[cur].size(); i++) {		
			int next = adj[cur][i].first;
			int nextDist = cost + adj[cur][i].second;
			if (dist[next] > nextDist) {				
				dist[next] = nextDist;					
				pq.push(make_pair(-nextDist, next));	
				visited[next] = cur;		
			}
		}
	}

	for (int i = 1; i <= numofV; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}

	delete[] adj;
	delete[] dist;
	delete[] visited;
	return 0;
}