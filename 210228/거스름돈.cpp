#include <string>
#include <vector>
#define MOD 1000000007;
using namespace std;

long long dp[100001];

// 백준: 동전 0 과 비슷한 문제
// 단순히 dp[i]=dp[i-1]+dp[i-3]+dp[i-5] 로 하면 중복이 발생한다. 
// 따라서 money에 들어 있는 단위 동전을 하나씩 추가하는 방법으로 진행해야한다. 

int solution(int n, vector<int> money) {
    int answer = 0;
    // money에 들어있는 거스름돈 단위 사용 가능

    for(int i=0;i<money.size();i++){
        int unit = money[i];
        dp[unit]+=1;
        for(int i=1;i<=n;i++){
            if(i-unit<=0)
                continue;
            // 만약 현재 단위가 5원이고 거스름돈이 7원이면 dp[7] += dp[2] (5원을 더해주기만 하면 된다.)
            dp[i]+=dp[i-unit]%MOD;
        }
    }
    answer = dp[n];
    
    return answer;
}