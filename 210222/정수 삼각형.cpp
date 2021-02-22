#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dp[501][501]={0,};
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            // 양 끝 dp처리
            if(j==0){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
            }
            else if(j==i){
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            }
            // 그렇지 않으면 위에서 더할 수 있는 두 수 중에서 값이 더 큰 값과 더한다.
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
    }
    
    for(int i=0;i<triangle.size();i++){
        answer = max(answer,dp[triangle.size()-1][i]);
    }
    return answer;
}