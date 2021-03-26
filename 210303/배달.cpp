#include <bits/stdc++.h>

using namespace std;

int selectNext(vector<int> cost, vector<bool> check) {
	int end = 0; 
	int min = 500001;
	for (int i = 1; i < cost.size(); i++) {
		if (check[i] == false && cost[i] < min) {		
			min = cost[i];
			end = i;
		}
	}
	return end;
}


int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<map<int, int>> graph(N + 1);	
	vector<int> cost(N + 1, 500001);		
	vector<bool> check(N + 1, false);
	
	cost[1] = 0;	

	for (int i = 0; i < road.size(); i++) {		
		if (graph[road[i][0]].find(road[i][1]) != graph[road[i][0]].end()) {		
			if (graph[road[i][0]][road[i][1]] > road[i][2]) {						
				graph[road[i][0]][road[i][1]] = road[i][2];
				graph[road[i][1]][road[i][0]] = road[i][2];
			}
		}
		
		else {		
			graph[road[i][0]].insert(make_pair(road[i][1], road[i][2]));
			graph[road[i][1]].insert(make_pair(road[i][0], road[i][2]));
		}
	}

	for (int i = 0; i < N - 1; i++) {		
		int end = selectNext(cost, check);			
		
		for (auto j : graph[end]) {			
			if (check[j.first] == false)	
				cost[j.first] = min(cost[j.first], cost[end] + j.second);		
		}
		check[end] = true;
	}

	for (int i = 1; i < cost.size(); i++) {
		
		if (cost[i] <= K)
			answer++;
	}

	return answer;
}