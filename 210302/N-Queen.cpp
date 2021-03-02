#include <string>
#include <vector>

using namespace std;
int pos[13];
bool visited[13]={false,};
int answer = 0;
// bactracking으로 가능한 경우의 수 모두 진행 
// 특징 1. 한 행 & 열에는 한 개만 존재 
// 특징 2. 대각선 존재 x

// 여왕의 좌표 표시 a[3]=2 (3행 2열 존재)

// x행 y열에 여왕을 넣어도 되는지 확인
bool canGo(int x, int y){
    if(visited[y])
        return false;
    for(int i=1;i<x;i++){
        int bx = i;
        int by = pos[i];
        if(abs(bx-x)==abs(by-y)){
            return false;
        }
    }
    return true;
}

void dfs(int x, int n){
    if(x>n){
        answer++;
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(canGo(x,i)){
            visited[i]=true;
            pos[x]=i;
            dfs(x+1,n);
            visited[i]=false;
        }
    }
    return;
}

int solution(int n) {
    dfs(1,n);
    return answer;
}