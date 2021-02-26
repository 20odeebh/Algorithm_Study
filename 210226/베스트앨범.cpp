#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
unordered_map <string,int> m;
vector<pair<string,int>> v;

// 정렬 + map 문제

bool cmp(pair<string,int>p1, pair<string,int>p2){
    return p1.second>p2.second;
}

bool cmp_tmp(pair<int,int>p1, pair<int,int>p2){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
        return p1.first>p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++){
        string genre = genres[i];
        int cnt = plays[i];
        m[genre]+=cnt;
    }
    
    // 많이 재생된 장르 순으로 정렬
    v.assign(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<v.size();i++){
        string genre = v[i].first;
        // 현재 장르 일치하는 노래 넣음
        vector<pair<int,int>> tmp;
        for(int j=0;j<genres.size();j++){
            if(genres[j]==genre){
                // 횟수와 인덱스 넣기
                tmp.push_back({plays[j],j});
            }
        }
        // 정렬
        sort(tmp.begin(),tmp.end(),cmp_tmp);
        // 한개만 있을 경우 
        if(tmp.size()==1){
            answer.push_back(tmp[0].second);
        }
        else{ 
            for(int i=0;i<2;i++){
                answer.push_back(tmp[i].second);
            }
        }
    }
    return answer;
}