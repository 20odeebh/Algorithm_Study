#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ti[17];
int pi[17];
int dp[2000];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ti[i] >> pi[i];
	for (int i = 0; i <= N; i++) {
		int next = i + ti[i];
		dp[next] = max(dp[next], dp[i] + pi[i]);
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	int answer = *max_element(dp, dp + N + 1);
	printf("%d\n", answer);
	return 0;
}