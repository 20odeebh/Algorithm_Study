#include <bits/stdc++.h>

using namespace std;
// queue에 위치와 방향, weight 저장
// visited 배열은 방향도 함께 

struct INFO{
    int x,y,dir;
};

int cost[30][30][4];
queue<INFO> q;
int n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool IsRange(int nx, int ny){
    if(nx>=0 && nx<n && ny>=0 && ny<n)
        return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    n = board.size();
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            for (int l = 0; l < 4; l++) 
                cost[i][j][l] = -1;

    for(int i=0;i<4;i++){
        q.push({0,0,i});
        cost[0][0][i]=0;
    }

    
    while(!q.empty()){
        INFO cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(IsRange(nx,ny) && board[nx][ny]==0){
                if(i==cur.dir){
                    if(cost[nx][ny][i]==-1 || cost[nx][ny][i]>cost[cur.x][cur.y][cur.dir]+100){
                        cost[nx][ny][i]=cost[cur.x][cur.y][cur.dir]+100;
                        q.push({nx,ny,i});
                    }
                }
                else{
                    if(cost[nx][ny][i]==-1 || cost[nx][ny][i]>cost[cur.x][cur.y][cur.dir]+100){
                        cost[nx][ny][i]=cost[cur.x][cur.y][cur.dir]+600;
                        q.push({nx,ny,i});
                    }                    
                }
            }
        }
    }
    
    for(int i=0;i<4;i++){
        if(cost[n-1][n-1][i]==-1)
            continue;
        answer = min(answer, cost[n-1][n-1][i]);
    }
    
    return answer;
}