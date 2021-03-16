#include <iostream>
#include <string.h>
using namespace std;
#define MAX_SIZE 16
int N;
int field[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1][3];
//dp[R][C][D] = �������� R, C���� �����Ͽ� N, N���� ���� D�� �����ϴ� ����� ��
//���� 0, 1, 2 : ����, �밢��, ����
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
	//ó������ ���η� ����
	dfs(1, 2, 2);
	int answer = dp[1][2][2];
	printf("%d\n", answer);
	return 0;
}