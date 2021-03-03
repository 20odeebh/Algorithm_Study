#include <bits/stdc++.h>

using namespace std;
// 54분

// 다익스트라로 1번에서 최단거리 구하기 
// 양방향 연결

vector<int> dist;
vector<pair<int,int>> edge[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=0;i<road.size();i++){
        int a = road[i][0];
        int b = road[i][1];
        int w = road[i][2];
        edge[a].push_back({b,w});
        edge[b].push_back({a,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    dist = vector<int>(N+1,INT_MAX);
    dist[1]=0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();
        for(auto &k:edge[cur]){
            int nidx = k.first;
            int weight = k.second;
            if(dist[nidx]>cur_weight+weight){
                dist[nidx]=cur_weight+weight;
                pq.push({dist[nidx],nidx});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(dist[i]<=K)
            answer++;
    }
    return answer;
}