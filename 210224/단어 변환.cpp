#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 50개의 단어 -> Brute Force로 모든 방법을 진행해본다.

bool visited[51]={false,};
string end_str;
int answer = 100;

// 두 문자열 a,b가 차이나는 문자가 1개인지 확인
bool canChange(string a, string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
            cnt++;
        if(cnt>1)
            return false;
    }
    return true;
}

void dfs(string cur, int depth, vector<string> &words){
    if(cur == end_str){
        // target이 나오면 answer 갱신 (dfs를 사용할 때 바로 return 하면 안됨, 최솟값 보장 안됨)
        answer = min(answer, depth);
        return;
    }
    for(int i=0;i<words.size();i++){
        // 다시 돌아가지 않기 위해 visited 배열, 한 개의 알파벳만 바꾸기 위한 canChange 함수
        if(!visited[i] && canChange(cur,words[i])){
            visited[i]=true;
            dfs(words[i],depth+1,words);
            visited[i]=false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    end_str = target;
    bool flag=false;
    // words에 target단어가 없을 때
    for(auto &k:words){
        if(k==target){
            flag=true;
            break;
        }
    }
    if(!flag)
        return 0;
    
    dfs(begin,0,words);
    
    return answer;
}