#include <iostream>
#include <string.h>
using namespace std;
#define CONST 1000000009
int tc;
long long dp[1000001];
void ButtomUp(int num)
{
	if (dp[num] != 0)
		return;
	for (int j = 4; j <= num; j++)
		dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % CONST;
}
long long dfs(int num)
{
	if (dp[num] != 0)
		return dp[num];
	dp[num] = (dfs(num - 1) + dfs(num - 2) + dfs(num - 3)) % CONST;
	return dp[num];
}
void TopDown(int num)
{
	if (dp[num] != 0)
		return;
	dfs(num);
}
int main()
{
	cin >> tc;
	int num;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 0; i < tc; i++) {
		cin >> num;
		//ButtomUp(num);
		TopDown(num);
		cout << dp[num] << endl;
	}
	return 0;
}