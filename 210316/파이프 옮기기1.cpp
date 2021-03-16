#include <iostream>
#include <string.h>
using namespace std;
#define MAX_SIZE 16
int N;
int field[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1][3];
//dp[R][C][D] = 파이프가 R, C에서 시작하여 N, N까지 방향 D로 도달하는 경우의 수
//방향 0, 1, 2 : 세로, 대각선, 가로
int dfs(int r, int c, int d)
{
	if (r > N || c > N)
		return 0;
	if (r == N && c == N)
		return 1;
	if (dp[r][c][d] == -1) {
		dp[r][c][d] = 0;
		switch (d) {
		case 0:
			if (field[r + 1][c] == 0)
				dp[r][c][d] += dfs(r + 1, c, 0);
			if (field[r][c + 1] == 0 &&
				field[r + 1][c + 1] == 0 &&
				field[r + 1][c] == 0)
				dp[r][c][d] += dfs(r + 1, c + 1, 1);
			break;
		case 1:
			if (field[r + 1][c] == 0)
				dp[r][c][d] += dfs(r + 1, c, 0);
			if (field[r][c + 1] == 0 &&
				field[r + 1][c + 1] == 0 &&
				field[r + 1][c] == 0)
				dp[r][c][d] += dfs(r + 1, c + 1, 1);
			if (field[r][c + 1] == 0)
				dp[r][c][d] += dfs(r, c + 1, 2);
			break;
		case 2:
			if (field[r][c + 1] == 0 &&
				field[r + 1][c + 1] == 0 &&
				field[r + 1][c] == 0)
				dp[r][c][d] += dfs(r + 1, c + 1, 1);
			if (field[r][c + 1] == 0)
				dp[r][c][d] += dfs(r, c + 1, 2);
			break;
		}
	}
	return dp[r][c][d];
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> field[i][j];
	memset(dp, -1, sizeof(dp));
	//처음에는 가로로 놓임
	dfs(1, 2, 2);
	int answer = dp[1][2][2];
	printf("%d\n", answer);
	return 0;
}