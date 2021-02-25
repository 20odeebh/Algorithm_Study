#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007;
using namespace std;
int arr[101][101]={0,};
int dp[101][101]={0,};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    // 물 웅덩이 표시
    for(int i=0;i<puddles.size();i++){
        arr[puddles[i][1]][puddles[i][0]]=1;
    }
    
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // 물 웅덩이는 0으로 유지
            if(arr[i][j]==1)
                continue;
            if(i==1 && j==1)
                continue;
            // 오른쪽, 왼쪽에서 올 수 있는 경우를 더한다.
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    answer = dp[n][m];
    
    return answer;
}