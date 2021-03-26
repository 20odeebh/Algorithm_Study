#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int m = board.size();
    int n = board[0].size();
    if(m == 1 || n == 1) return 1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(board[i][j]){
                int a = board[i-1][j-1];
                int b = board[i-1][j];
                int c = board[i][j-1];
                int min = a<b?a:b;
                min = min<c? min:c;
                board[i][j]=min+1;
                answer=max(answer,board[i][j]*board[i][j]);
            }
        }
    }

    return answer;
}