#include <bits/stdc++.h>

using namespace std;
// 1에서 각 노드별 거리 구하기 
// 가중치 없음 -> bfs
vector<int> edges[20001];
bool visited[20001]={false,};
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_val=0;
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;
    
    for(int i=0;i<edge.size();i++){
        edges[edge[i][0]].push_back(edge[i][1]);
        edges[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    visited[1]=true;
    q.push(1);
    dist[1]=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto &k:edges[cur]){
            if(!visited[k]){
                visited[k]=true;
                dist[k]=dist[cur]+1;
                max_val = max(max_val, dist[k]);
                q.push(k);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(dist[i]==max_val)
            answer++;
    }
    return answer;
}