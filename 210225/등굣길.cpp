#include <string>
#include <vector>
int dirRow[] = { 1, 0 };
int dirCol[] = { 0, 1 };
using namespace std;
#define CONST_NUM 1000000007
int dp[101][101];
int M, N;
int dfs(int row, int col)
{
	if (row == M && col == N)
		return 1;
	int nc, nr;
	if (dp[row][col] == 0) {
		for (int i = 0; i < 2; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr > M || nc > N)
				continue;
			dp[row][col] += dfs(nr, nc);
		}
		return dp[row][col] % CONST_NUM;
	}

	else if (dp[row][col] == -1)
		return 0;

	else
		return dp[row][col] % CONST_NUM;
}
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	M = m, N = n;
	for (const auto& p : puddles)
		dp[p[0]][p[1]] = -1;
	dfs(1, 1);
	answer = dp[1][1] % CONST_NUM;
	return answer;
}