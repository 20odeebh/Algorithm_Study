#include <iostream>
using namespace std;
long long dp[100001][4];
int Max = 4;
#define CONST 1000000009
void BottomUp(int num)
{
	if (dp[num][1] || dp[num][2] || dp[num][3])
		return;

	for (int i = Max; i <= num; i++) {
		for (int j = 1; j <= 3; j++) {
			switch (j) {
			case 1:
				dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % CONST;
				break;
			case 2:
				dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % CONST;
				break;
			case 3:
				dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % CONST;
				break;
			}
		}
	}

	Max = num;
}
int main()
{
	int tc, num;
	long long answer = 0;
	cin >> tc;
	dp[1][1] = 1, dp[2][2] = 1, dp[3][3] = 1;
	dp[3][1] = 1, dp[3][2] = 1;
	for (int t = 0; t < tc; t++) {
		cin >> num;
		BottomUp(num);
		answer = (dp[num][1] + dp[num][2] + dp[num][3]) % CONST;
		printf("%lld\n", answer);
	}
	return 0;
}