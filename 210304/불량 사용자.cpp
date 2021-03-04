#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
// 완전 탐색 (크기가 8)
vector<string> user;
vector<string> ban;
int answer = 0;
bool visited[10]={false,};
vector<int> res;
set<string>s;

// 제재 아이디가 맞는지 확인
bool canBanned(string u, string b){
    if(u.size()!=b.size())
        return false;
    for(int i=0;i<b.size();i++){
        if(b[i]=='*')
            continue;
        if(b[i]!=u[i])
            return false;
    }
    return true;
}

// 모든 조합에 대해서 탐색
void dfs(int cnt){
    if(cnt==ban.size()){
        string tmp;
        for(auto &k:res)
            tmp+=k+'0';
        sort(tmp.begin(),tmp.end());
        // 반복되는 조합이 있으면 안되기 때문에 인덱스를 string으로 저장해서 set에서 확인
        if(s.find(tmp)==s.end()){
            answer++;
            s.insert(tmp);
        }
        return;
    }
    string cur_banned = ban[cnt];
    for(int i=0;i<user.size();i++){
        string cur_user = user[i];
        if(!visited[i] && canBanned(cur_user,cur_banned)){
            res.push_back(i);
            visited[i]=true;
            dfs(cnt+1);
            res.pop_back();
            visited[i]=false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;
    dfs(0);
    
    return answer;
}