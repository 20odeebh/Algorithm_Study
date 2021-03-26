#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

bool isEnd(bool check[], int n) {
	for (int i = 0; i < n; i++) {
		if (check[i] == false)
			return false;
	}
	return true;
}

struct cmp_cost {				
	bool operator()(vector<int> t, vector<int> u) {
		return t[2] > u[2];
	}
};


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	bool check[101] = { false, };
	int pos = 0;
	list<vector<int>> l;

	for (int i = 0; i < costs.size(); i++)
		l.push_back(costs[i]);
		
	check[(*l.begin())[0]] = true;		
	
	while (!isEnd(check, n)) {
		priority_queue <vector<int>, vector<vector<int>>, cmp_cost > pq_island;
		for (int i = 0; i < n; i++) {
			
			if (check[i]) {		
				for (auto j : l) {		
					if ((j[0] == i && check[j[1]]!=true) || (j[1] == i && check[j[0]]!=true))
						pq_island.push(j);
				}
			}
		}
		vector<int> v = pq_island.top();				
		answer += v[2];									
		
		check[v[0]] = true;								
		check[v[1]] = true;								
		
		l.erase(find(l.begin(), l.end(), v));
	}

	return answer;
}