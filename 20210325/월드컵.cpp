#include<iostream>
using namespace std;

int t1[20] = { 1,1,1,1,1,2,2,2,2,3,3,3,4,4,5 };
int t2[20] = { 2,3,4,5,6,3,4,5,6,4,5,6,5,6,6 };
int res[10][10];
int map[5][10][10];
int ans[5];
void dfs(int depth);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int t = 1; t <= 4; ++t)
	{
		for (int i = 1; i <= 6; ++i)
		{
			for (int j = 1; j <= 3; ++j)
			{
				cin >> map[t][i][j];
			}
		}
	}

	dfs(0);

	for (int i = 1; i <= 4; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}
void dfs(int depth)
{
	if (depth == 15)
	{
		for (int t = 1; t <= 4; ++t)
		{
			bool temp = true;

			for (int i = 1; i <= 6; ++i)
			{
				for (int j = 1; j <= 3; ++j)
				{
					if (map[t][i][j] != res[i][j]) 
					{
						temp = false;
						break;
					}
				}
				if (!temp) break;
			}

			if (temp)
			{
				ans[t] = 1;
			}
		}
		return;
	}

	int num1 = t1[depth];
	int num2 = t2[depth];

	++res[num1][1];
	++res[num2][3];
	dfs(depth + 1);
	--res[num1][1];
	--res[num2][3];

	++res[num1][2];
	++res[num2][2];
	dfs(depth + 1);
	--res[num1][2];
	--res[num2][2];

	++res[num1][3];
	++res[num2][1];
	dfs(depth + 1);
	--res[num1][3];
	--res[num2][1];
}