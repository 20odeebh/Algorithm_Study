#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define INF 999999999
#define max_n 20
using namespace std;

int n;
int n_half;
int ans;
int map[max_n + 1][max_n + 1];
bool check[max_n + 1];
void input();
void dfs(int cur, int depth);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//조합을 통해 팀을 나누고, 각팀의 능력치 최소값
	input();

	ans = INF;
	n_half = n / 2;

	dfs(1, 0);

	cout << ans << '\n';

	return 0;
}
void dfs(int cur, int depth)
{
	if (depth == n_half)
	{
		int sum1, sum2;
		sum1 = sum2 = 0;

		vector<int> t1;
		vector<int> t2;

		for (int i = 1; i <= n; ++i)
		{
			if (check[i]) t1.push_back(i);
			else t2.push_back(i);
		}

		for (int i = 0; i < n_half; ++i)
		{
			for (int j = i + 1; j < n_half; ++j)
			{
				sum1 += map[t1[i]][t1[j]];
				sum1 += map[t1[j]][t1[i]];

				sum2 += map[t2[i]][t2[j]];
				sum2 += map[t2[j]][t2[i]];
			}
		}

		ans = min(ans, abs(sum1 - sum2));
		return;
	}
	for (int i = cur; i <= n; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(i, depth + 1);
			check[i] = false;
		}
	}
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