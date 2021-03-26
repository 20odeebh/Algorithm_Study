#include <string>
#include <vector>

using namespace std;

int memo[100000];

int fibo(int n){
    memo[0] = 0;
    memo[1]= 1;
    for(int i=2;i<=n;i++){
        memo[i] = (memo[i-1]%1234567) +(memo[i-2]%1234567);
    }
    return memo[n];
}

int solution(int n) {
    int answer = 0;
    answer = fibo(n)%1234567;
    return answer;
}
