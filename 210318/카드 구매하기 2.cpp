#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
int arr[1001];
int dp[1001];
#define INF 987654321
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}