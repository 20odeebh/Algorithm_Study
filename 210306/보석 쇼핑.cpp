#include <bits/stdc++.h>

using namespace std;

unordered_set<string>s;
// 종류 개수 set에 저장
// 슬라이딩 윈도우로 모든 값이 들어오면 체크
unordered_map<string,int>m;
int min_idx;
int max_idx;
vector<pair<int,pair<int,int>>>v;

bool cmp(pair<int,pair<int,int>>p1, pair<int,pair<int,int>>p2){
    if(p1.first==p2.first)
        return p1.second.first<p2.second.first;
    return p1.first<p2.first;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for(auto &k:gems)
        s.insert(k);
    
    int n = s.size();
    
    for(int i=0;i<gems.size();i++){
        min_idx = min(min_idx,i);
        max_idx = max(max_idx,i);
        m[gems[i]]++;
        // 모든 종류의 보석이 들어오면 앞에서부터 모든 종류의 보석이 없을 때까지 값을 뺀다.
        while(m.size()==n){
            v.push_back({max_idx-min_idx,{min_idx+1,max_idx+1}});
            string target = gems[min_idx];
            if(m[target]>1){
                m[target]--;
            }
            else
                m.erase(target);
            min_idx++;   
        }
    }
    
    sort(v.begin(),v.end(),cmp);
    answer.push_back(v.front().second.first);
    answer.push_back(v.front().second.second);

    return answer;
}