#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(),works.end());
    
    for(int i=0;i<n;i++){
        if(pq.top()>0){
           int t=pq.top();
            pq.pop();
            pq.push(t-1);
        }       
    }
    while(!pq.empty()){
        int t=pq.top();
        answer += t*t;
        pq.pop();
    }
    return answer;
}