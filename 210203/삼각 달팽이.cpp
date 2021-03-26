#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    
    int cnt = 1,y = 0, x = 0;
    
    for(int len = n - 1; len >= 0; len -= 3) {
        
        // 하나만 았을 때
        if(len == 0) {
            a[y][x] = cnt;
            break;
        }
        
        //위에서 왼쪽 아래로
        for(int i = 0; i < len; i++) {
            a[y][x] = cnt++;
            y++;
        }
        
        //다 채웠으면 끝
        if(a[y][x]) {
            break;
        }
        
        //왼쪽 아래에서 오른쪽 아래로
        for(int i = 0; i < len; i++) {
            a[y][x] = cnt++;
            x++;
        }
        
        if(a[y][x]) {
            break;
        }

        //오른쪽 아래에서 위로
        for(int i = 0; i < len; i++) {
            a[y][x] = cnt++;
            x--;y--;
        }
        
        //시작점으로 좌표 이동
        y += 2;
        x++;

    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j]) answer.push_back(a[i][j]);
        }
    }
    
    
    return answer;
}