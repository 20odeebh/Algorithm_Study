#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;
int n, t;
int arr[105][105] = { 0, };
int cnt = 0;
bool visited[105] = { false, };

void dfs(int idx) {
	for (int i = 1; i <= n; i++) {
		if (arr[idx][i] == 1 && !visited[i]) {
			visited[i] = true;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t;
	while (t--) {
		int n1, n2; cin >> n1 >> n2;
		arr[n1][n2] = 1;
		arr[n2][n1] = 1;
	}

	visited[1] = true;
	dfs(1);

	cout << cnt;
}