#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_SIZE 100001
int arr[2][MAX_SIZE];
int dp[2][MAX_SIZE];
/*
dp[0][N] = 0번째 행의 최댓값
dp[1][N] = 1번째 행의 최댓값
dp[0][N] = max(dp[0][N - 2], dp[1][N - 1] + arr[0][N])
dp[1][N] = max(dp[1][N - 2], dp[0][N - 1] + arr[1][N])
*/
int main()
{
	int tc, K;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> K;
		for (int k = 0; k < K; k++)
			cin >> arr[0][k];
		for (int k = 0; k < K; k++)
			cin >> arr[1][k];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = arr[0][0], dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < K; i++) {
			dp[0][i] = max(dp[1][i - 2] + arr[0][i], dp[1][i - 1] + arr[0][i]);
			dp[1][i] = max(dp[0][i - 2] + arr[1][i], dp[0][i - 1] + arr[1][i]);
		}
		printf("%d\n", max(dp[0][K - 1], dp[1][K - 1]));
	}
	return 0;
}