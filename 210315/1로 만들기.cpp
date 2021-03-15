#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 1e6 + 1
/*
dp[n] = min(dp[n / 3] + 1,
dp[n / 2] + 1,
dp[n - 1] + 1)
*/
int X;
int dp[1000001];
int main()
{
	cin >> X;
	if (X == 1) {
		printf("0\n");
		return 0;
	}
	memset(dp, INF, sizeof(dp));
	dp[X] = 0;
	for (int i = X; i > 1; i--) {
		if (i % 3 == 0)
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		if (i % 2 == 0)
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	printf("%d\n", dp[1]);
	return 0;
}