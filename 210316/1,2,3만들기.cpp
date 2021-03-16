#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		int num; cin >> num;
		vector<int> dp(20, 0);
		dp[1] = 1; dp[2] = 2; dp[3] = dp[1] + dp[2] + 1;
		for (int i = 4; i <= num; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		cout << dp[num] << '\n';
	}
}