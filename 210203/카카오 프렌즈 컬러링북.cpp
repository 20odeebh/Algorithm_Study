#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool ch[101][101];
int dy[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int bfs(int val, int x, int y, int m, int n, vector<vector<int>> picture){
    queue<pair<int,int>> q;
    q.push({x,y});
    ch[x][y] = 1;
    int area = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i][1];
            int nx = x + dy[i][0];            
            if( nx <0 || nx>=m || ny<0 || ny>=n ||ch[nx][ny] || picture[nx][ny] != val  ) continue;
            q.push({nx,ny});
            ch[nx][ny] = 1;
            area++;
        }
    }
    return area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ch[i][j] = 0;
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!ch[i][j] && picture[i][j]>0){
                int area = bfs(picture[i][j], i, j, m, n, picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }
   
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}