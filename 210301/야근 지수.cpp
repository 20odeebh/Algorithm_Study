#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 제곱의 합을 최소한으로 줄여야한다. 
// 값들을 비슷하게 만들어야한다. 
// 그리디 : 벡터에 저장된 가장 큰 값을 줄인다. 항상 정렬하면 시간 복잡도가 크다. 따라서 pq 사용
// 시간 복잡도 : O(nlogn)
priority_queue<int>pq;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(auto &k:works)
        pq.push(k);
    
    bool flag=true;
    
    while(n!=0){
        int num = pq.top();
        if(num==0){
            flag=false;
            break;
        }
        pq.pop();
        n--;
        pq.push(num-1);
    }
    
    if(!flag)
        return 0;
    else
    {
        while(!pq.empty()){
            answer+=pq.top()*pq.top();
            pq.pop();
        }
    }
    return answer;
}