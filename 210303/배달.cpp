#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int graph[51][51];
int INF = 10001;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	memset(graph, INF, sizeof(graph));
	for (int i = 0; i<road.size(); i++) {
		graph[road[i][0]][road[i][1]] = graph[road[i][1]][road[i][0]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) graph[i][i] = 0;
	for (int i = 1; i <= N; i++) {
		if (graph[1][i] <= K) answer++;
	}
	return answer;
}