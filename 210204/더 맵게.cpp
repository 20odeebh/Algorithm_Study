#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int a:scoville) pq.push(a);
    while(pq.top()<K && pq.size()>1){
    int a=pq.top();
    pq.pop();
    int b=pq.top();
    pq.pop();
    pq.push(a+2*b);
    answer++;
    }
    if(pq.size()==1 && pq.top() < K) return -1;
    return answer;
}