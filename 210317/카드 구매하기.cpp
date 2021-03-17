#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n;
int dp[1001] = { 0, };
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], arr[j] + dp[i - j]);
		}
	}
	cout << dp[n];
}