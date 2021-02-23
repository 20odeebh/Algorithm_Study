#include <bits/stdc++.h>

using namespace std;

int answer,t,j;

int solution(vector<vector<int>> jobs) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    sort(jobs.begin(),jobs.end());
    
    while(j<jobs.size() || !pq.empty()){
        if(j<jobs.size() && t>=jobs[j][0]){
            pq.push({jobs[j][1],jobs[j][0]});
            j++;
            continue;
        }
        if(!pq.empty()){
          t += pq.top().first;
          answer += t-pq.top().second;
          pq.pop();            
        }
        else{
            t = jobs[j][0];
        }
    }
    
    return answer/jobs.size();
}