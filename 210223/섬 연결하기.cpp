#include <string>
#include <vector>
#include <queue>

using namespace std;
// 연결하는 최소 비용 -> MST, 크루스칼 알고리즘
// 그리디, 연결 비용 가장 작은 것부터 뽑기 (단, cycle 생성되면 안됨)
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

int parent[101];

int find(int x){
    if(parent[x]==x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int n1, int n2){
    int p1 = find(n1);
    int p2 = find(n2);
    if(p1!=p2)
        parent[p2] = p1;
    return;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // 초기화
    for(int i=0;i<n;i++)
        parent[i]=i;
    
    for(auto &k:costs){
        pq.push({k[2],{k[0],k[1]}});
    }
    
    while(!pq.empty()){
        int n1 = pq.top().second.first;
        int n2 = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();
        // n1과 n2를 연결했을 때 사이클이 생성되지 않는다면 연결
        if(find(n1)!=find(n2)){
            merge(n1,n2);
            answer+=w;
        }
    }
    
    return answer;
}