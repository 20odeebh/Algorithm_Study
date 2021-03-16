#include <iostream>
#include <string.h>
using namespace std;
int dp[1001];
int N;
int fibo(int n)
{
	if (dp[n] != -1)
		return dp[n];
	dp[n] = (fibo(n - 1) + fibo(n - 2) + fibo(n - 2)) % 10007;
	return dp[n];
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	dp[1] = 1;
	dp[2] = 3;
	printf("%d\n", fibo(N));
	return 0;
}