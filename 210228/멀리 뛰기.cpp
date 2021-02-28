#include <string>
#include <vector>
#define MOD 1234567;

using namespace std;
// 도달하는 방법 
// DP : 한칸 또는 두칸 뛸 수 있기 때문에 dp[i-1]에서 한칸, dp[i-2]에서 두칸을 뛰면 된다.

int dp[2001];

long long solution(int n) {
    long long answer = 0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    answer = dp[n];
    return answer;
}