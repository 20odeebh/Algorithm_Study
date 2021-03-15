#include <iostream>
#include <string.h>
using namespace std;
int N;
int dp[1001];
#define CONST 10007
int fibo(int n)
{
	if (dp[n] != 0)
		return dp[n];
	dp[n] = (fibo(n - 1) + fibo(n - 2)) % CONST;
	return dp[n];
}
int main()
{
	cin >> N;
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	printf("%d\n", fibo(N));
	return 0;
}