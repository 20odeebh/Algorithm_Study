#include <bits/stdc++.h>

using namespace std;

int N, visited[100001],parent[100001];
vector <int> v[100001];

void bfs() { 
	queue<int>q;
	q.push(1);
	visited[1] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int z = v[x][i];
			if (!visited[z]) {
				parent[z] = x;
				visited[z] = 1;
				q.push(z);
			}
		}
	}
}

void printparent() {
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}

int main() {
	cin >> N;
	int val1,val2;
	
	for (int i = 0; i < N-1; i++) {
		cin >> val1>>val2;
		v[val1].push_back(val2);
		v[val2].push_back(val1);
	}
	bfs();
	printparent();
}
