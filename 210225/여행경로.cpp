#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visited[100001]={false,};
vector<vector<string>> ticket;
vector<string> answer;
vector<string> tmp;
// 가장 순서가 빠른 쪽으로 찾아가는 알고리즘은 "그리디"
// 이 방법은 빠른 것을 먼저 찾아가긴 하지만 항상 그 방법이 맞는 것이 아니다.
// (빠른 쪽만 찾아가다가 모든 도시를 방문하지 못할 수 도 있음)
// 따라서 backtracking을 사용해서 모든 경우의 수를 확인해줘야한다.

bool flag=false;

void dfs(string str){
    // 경로 찾았으면 더 이상 진행하지 않고 return 
    if(flag)
        return;
    
    if(tmp.size()==ticket.size()+1){
        flag=true;
        answer = tmp;
        return;
    }
    
    // 현재 갈 수 있는 것 중 알파벳 순서가 앞서는 것으로 넣어준다.
    vector<pair<string,int>>v;
    
    for(int i=0;i<ticket.size();i++){
        if(!visited[i] && ticket[i][0]==str){
            v.push_back({ticket[i][1],i});
        }
    }
    sort(v.begin(),v.end());
    for(auto &k:v){
        visited[k.second]=true;
        tmp.push_back(k.first);
        dfs(k.first);
        tmp.pop_back();
        visited[k.second]=false;
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    ticket=tickets;
    tmp.push_back("ICN");
    dfs("ICN");
    
    for(auto &k:tmp)
        cout << k << ' ';
    
    return answer;
}