#include <bits/stdc++.h>
using namespace std;
vector<int> v[20001];
int d[20001];
queue<int> q;
//bfs로 1과의 거리를 계산
//가장 먼 곳의 노드 개수를 센다
void bfs(int start) {
    q.push(start);
    d[start] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto k : v[x]) {
            if (d[k] == 0) {
                d[k] = d[x] + 1;
                q.push(k);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int size = edge.size();
    for (int i = 1; i <= n; i++)d[i] = 0;
    for (int i = 0; i < size; i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    int MAX = 0;
    for (int i = 2; i <= n; i++)MAX = max(MAX, d[i]);
    for (int i = 2; i <= n; i++) {
        if (d[i] == MAX)answer++;
    }
    return answer;
}