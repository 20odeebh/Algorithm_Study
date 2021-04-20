#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define max_n 4
using namespace std;

vector<int> ans;
vector<string> temp;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int map[max_n + 1][max_n + 1];
int n;
void input();
void solution();
void dfs(int cur_x, int cur_y, int depth, string str);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		input();
		solution();
		temp.clear();
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}
void solution()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			string str = "";
			str += char(map[i][j] + '0');
			dfs(i, j, 1, str);
		}
	}

	sort(temp.begin(), temp.end());

	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	
	ans.push_back(temp.size());
}
void dfs(int cur_x, int cur_y, int depth, string str)
{
	if (depth == 7)
	{
		temp.push_back(str);

		return;
	}
	for (int k = 0; k < 4; ++k)
	{
		int nx = cur_x + dx[k];
		int ny = cur_y + dy[k];

		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		dfs(nx, ny, depth + 1, str + char(map[nx][ny] + '0'));
	}

}
void input()
{
	n = 4;
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}