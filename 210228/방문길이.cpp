#include <string>
#include <unordered_map>

using namespace std;


unordered_map<char,int>m;
// 각 좌표에는 여러번 방문할 수 있지만 방향에 따라서 다르다.
bool visited[11][11][4]={false,};

bool IsRange(int x, int y){
    if(x>=0 && x<=10 && y>=0 && y<=10)
        return true;
    return false;
}

int dx[4]={-1,1,0,0};
int dy[4] = {0,0,1,-1};

int solution(string dirs) {
    int answer = 0;
    // 시작 위치 바꿔줌
    int x=5;
    int y=5;
    // 만약 (5,5)에서 (5,6)으로 이동하면 (5,6,'U') 와 (5,6,'D') 을 모두 방문처리 한다.
    // 두 직선은 모두 방문했다는 표시이기 때문
    char dir[4] = {'U','D','R','L'};
    char rdir[4] = {'D','U','L','R'};
    for(int i=0;i<4;i++){
        m.insert({dir[i],i});
    }
    
    for(int i=0;i<dirs.size();i++){
        char dir = dirs[i];
        int idx = m[dir];
        int nx = x+dx[idx];
        int ny = y+dy[idx];
        // 범위 안에 있을 때
        if(IsRange(nx,ny)){
            // 방문하지 않았으면 양 방향 모두 방문 표시 후 answer 증가
            if(!visited[nx][ny][idx]){
                visited[nx][ny][idx]=true;
                visited[x][y][m[rdir[idx]]]=true;
                answer++;
            }
            x=nx,y=ny;
        }
        // 방문하지 않으면 명령어 pass
    }
    
    return answer;
}