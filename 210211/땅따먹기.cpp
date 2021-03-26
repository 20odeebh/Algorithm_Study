#include <iostream>
#include <vector>

using namespace std;

int dp[100000][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i=0;i<4;i++){
        dp[0][i]=land[0][i];
    }
 
    for(int i=1;i<land.size();i++){
        //지금열
        for(int j=0;j<4;j++){
            int mx=0;
            //전의 열
            for(int k=0;k<4;k++){
                if(j == k) continue;
                if(mx<=dp[i-1][k]) mx=dp[i-1][k];              
            }
            dp[i][j] = mx + land[i][j];
        }
    }
 
    for(int i=0;i<4;i++){
        answer=max(answer, dp[land.size()-1][i]);       
    }
    
    return answer;
}
