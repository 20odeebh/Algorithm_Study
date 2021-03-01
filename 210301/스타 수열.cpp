#include <bits/stdc++.h>

using namespace std;

// 각 집합에 공통되는 수가 하나 이상 존재 
// 1. 각 숫자가 몇개 존재하는지 저장 후 정렬
// 2. 가장 많은 숫자가 존재하는 숫자부터 부분 수열의 길이를 찾음
// 3. 만약 현재 숫자가 앞서 결정된 부분 수열의 길이를 넘을 수 없다면 계산을 끝냄.

map<int,int>m;

bool cmp(pair<int,int>p1, pair<int,int>p2){
    return p1.second>p2.second;
}
int solution(vector<int> a) {
    int answer = 0;
    if(a.size()<2)
        return 0;
    for(auto &k:a)
        m[k]++;
    vector<pair<int,int>>v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);

    for(auto &k:v){
        int target = k.first;
        int cnt = k.second;
        
        if(cnt*2<answer)
            break;
        
        queue<int> q;
        for(auto &k:a)
            q.push(k);
        
        bool flag=false;
        int num_cnt=0;
        int total=0;
        // target 값 하나와 다른 값 하나가 있을 때만 부분 수열 개수(total) 증가
        while(!q.empty()){
            if(q.front()==target){ 
                if(num_cnt>0){
                    total++;
                    flag=false;
                    num_cnt=0;
                }
                else
                    flag=true;
            }
            else{
                if(flag){
                    total++;
                    flag=false;
                    num_cnt=0;
                }
                else
                    num_cnt++;
            }
            q.pop();
        }
        answer = max(answer,total*2);
        
    }
    
    return answer;
}