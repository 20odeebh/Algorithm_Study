#include<iostream>
#define max_n 16
using namespace std;

int map[max_n + 1][max_n + 1];
int dp[max_n + 1][max_n + 1][3];
int n;
void input();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dp[1][2][0] = 1; // ����
	dp[1][2][1] = 0; // ����
	dp[1][2][2] = 0; // �밢

	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == 1 && j <= 2) continue; // ó���� ���θ�

			if (map[i][j] == 1)continue; // ��

			if (map[i][j - 1] == 1) dp[i][j][0] = 0;  // ����(����,�밢)
			else dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

			if (map[i - 1][j] == 1) dp[i][j][1] = 0; // ���� (�밢, ����)
			else dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

			if (map[i - 1][j] == 1 || map[i][j-1] == 1) dp[i][j][2] = 0; // �밢(3�� ��)
			else dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
	return 0;
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}