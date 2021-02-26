#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 순위가 결정될 수 있는 경우 : 나를 이긴 사람 + 내가 이긴 사람 합이 n-1
// 나를 이긴 사람에게는 항상 지고, 내가 진 사람에겐 항상 이긴다는 규칙이 있다. 
// 재귀를 통해 모두 찾아야한다.

vector<int> win[101];
vector<int> lose[101];
int answer=0;
bool visited[101]={false,};
int win_cnt=0;
int lose_cnt=0;

void find_lose(int idx){
    for(auto &k:win[idx]){
        if(!visited[k]){
            visited[k]=true;
            win_cnt++;
            find_lose(k);
        }
    }
    return;
}

void find_win(int idx){
    for(auto &k:lose[idx]){
        if(!visited[k]){
            visited[k]=true;
            lose_cnt++;
            find_win(k);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        int win_p = results[i][0];
        int lose_p = results[i][1];
        win[win_p].push_back(lose_p);
        lose[lose_p].push_back(win_p);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            visited[j]=false;
        
        win_cnt=0;
        lose_cnt=0;
        // 내가 이긴 선수를 모두 찾아가기 
        find_lose(i);
        // 나를 이긴 선수들 모두 찾아가기
        find_win(i);
        if(win_cnt+lose_cnt==n-1)
            answer++;
    }

    return answer;
}