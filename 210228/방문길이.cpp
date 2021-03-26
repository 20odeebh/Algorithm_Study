#include <string>

using namespace std;
int v[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int y=5,x=5;
    
    for(auto s: dirs){
        int ny=y;
        int nx=x;
        if(s == 'U') ny-=1;
        else if(s == 'D') ny+=1;
        else if(s == 'R') nx+=1;
        else nx-=1;
        if(ny<0||ny>10||nx<0||nx>10) continue;
        if(v[y][x][ny][nx] == 0){
            v[y][x][ny][nx]=1;
            v[ny][nx][y][x]=1;
            answer++;
        }
        y=ny;
        x=nx;
    }
    return answer;
}