#include <string>
#include <vector>

using namespace std;

string ans = "a";
int v[10000];
void go(vector<vector<string>> tickets,string cur,string path,int len){
    if(len == tickets.size()){
        if(path<ans) ans=path;
        return;
    }
        for(int i=0;i<tickets.size();i++){
            if(v[i] == 0 && tickets[i][0] == cur){
                v[i]=1;
                go(tickets,tickets[i][1],path+tickets[i][1],len+1);
                v[i]=0;
            }
        }
    
    
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    go(tickets,"ICN","ICN",0);
    for(int i=0;i<ans.size();i+=3){
        answer.push_back(ans.substr(i,3));
    }
    return answer;
}
