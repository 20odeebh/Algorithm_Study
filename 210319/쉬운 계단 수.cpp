#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int N;
#define CONST 1000000000
vector<long long> dp(10, 0);
int main()
{
	cin >> N;
	if (N == 1) {
		printf("9\n");
		return 0;
	}
	for (int i = 1; i <= 9; i++)
		dp[i] = 1;
	auto temp = dp;
	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				dp[0] = temp[1];
			}
			else if (i == 9) {
				dp[9] = temp[8];
			}
			else {
				dp[i] = (temp[i - 1] + temp[i + 1]) % CONST;
			}
		}
		temp = dp;
	}
	long long answer = 0;
	for (const auto& i : dp)
		answer += i;
	printf("%lld\n", answer % CONST);
	return 0;
}