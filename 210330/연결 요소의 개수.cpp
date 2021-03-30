#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];

int n, m;
int visit[1001];

void bfs(int start){
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			
			if (visit[nx] == 1) continue;
			q.push(nx);
			visit[nx] = 1;
		}
	}
}

int main(){
	cin >> n >> m;
	for (int a, b, i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bfs(i);
			res++;
		}
	}
	cout << res;
}
