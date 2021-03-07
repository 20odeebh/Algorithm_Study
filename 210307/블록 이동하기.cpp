#include <bits/stdc++.h>

using namespace std;
// BFS
unordered_set<string>visited;
int n;

struct INFO{
    int x1,y1,x2,y2,cnt;
};

// 좌 우 상 하
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

string make_cnt(int x1, int y1, int x2, int y2){
    string tmp;
    tmp += x1+'0';
    tmp += y1+'0';
    tmp += x2+'0';
    tmp += y2+'0';
    return tmp;
}


bool IsEnd(INFO info){
    if(info.x1==n-1 && info.y1==n-1)
        return true;
    if(info.x2==n-1 && info.y2==n-1)
        return true;
    return false;
}


bool IsRange(int x1, int y1, int x2, int y2){
    if(x1>=0 && x1<n &&y1>=0 && y1<n && x2>=0 && x2<n && y2>=0 && y2<n)
        return true;
    return false;
}

bool canGo(int x1, int y1, int x2, int y2, vector<vector<int>> &board){
    if(board[x1][y1]==0 && board[x2][y2]==0)
        return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n=board.size();
    // 끝
    queue<INFO> q;
    q.push({0,0,0,1,0});
    visited.insert(make_cnt(0,0,0,1));
    while(!q.empty()){
        INFO cur = q.front();
        q.pop();
        // 도착지점에 다다름
        if(IsEnd(cur)){
            answer=cur.cnt;
            break;
        }
        // 1. 상하좌우로 이동
        for(int i=0;i<4;i++){
            int nx1 = cur.x1+dx[i];
            int ny1 = cur.y1+dy[i];
            int nx2 = cur.x2+dx[i];
            int ny2 = cur.y2+dy[i];
            string ntmp = make_cnt(nx1,ny1,nx2,ny2);
            if(IsRange(nx1,ny1,nx2,ny2) && canGo(nx1,ny1,nx2,ny2,board) &&visited.find(ntmp)==visited.end()){
                visited.insert(ntmp);
                q.push({nx1,ny1,nx2,ny2,cur.cnt+1});
            }
        }
        // 2. 회전하기 두 개의 축을 기준으로 시계방향 or 반시계 방향으로 이동
        for(int i=0;i<4;i++){
            if(cur.y1==cur.y2 && (i==2 || i==3)) continue;
            if(cur.x1==cur.x2 && (i==0 || i==1)) continue;

            int nx1 = cur.x1+dx[i];
            int ny1 = cur.y1+dy[i];
            int nx2 = cur.x2+dx[i];
            int ny2 = cur.y2+dy[i];
            
            if(IsRange(nx1,ny1,nx2,ny2) && canGo(nx1,ny1,nx2,ny2,board)){
                if(visited.find(make_cnt(cur.x1,cur.y1,nx1,ny1))==visited.end()){
                    visited.insert(make_cnt(cur.x1,cur.y1,nx1,ny1));
                    q.push({cur.x1,cur.y1,nx1,ny1,cur.cnt+1});
                }
                if(visited.find(make_cnt(cur.x2,cur.y2,nx2,ny2))==visited.end()){
                    visited.insert(make_cnt(cur.x2,cur.y2,nx2,ny2));
                    q.push({cur.x2,cur.y2,nx2,ny2,cur.cnt+1});
                }
            }
        }
    }
    return answer;
}