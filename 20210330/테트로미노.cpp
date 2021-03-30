#include<iostream>
#include<algorithm>
#define max_n 500
using namespace std;

int n, m;
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans;
void dfs(int cur_x, int cur_y, int sum, int depth);
void input();
void check_func(int cur_x, int cur_y);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	
	cout << ans << '\n';
	
	return 0;
}
void solution()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visit[i][j] = true;
			dfs(i, j, map[i][j], 1); // �Ǹ���� ������, ������ ����� dfs�� Ÿ���鼭 4���� ������, üũ ����
			visit[i][j] = false;
			check_func(i,j); // �Ǹ�� üũ
		}
	}
}
void check_func(int cur_x, int cur_y)
{
	//���� ��ġ���� 3���� 
	int cnt = 0;
	int sum = map[cur_x][cur_y];

	for (int k = 0; k < 4; ++k)
	{
		int nx = cur_x + dx[k];
		int ny = cur_y + dy[k];
		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		++cnt;
		sum += map[nx][ny];
	}
	if (cnt == 3) ans = max(sum, ans); // 3���� max üũ
	else if (cnt == 4) // 4���� ��� ���� ���� �ƴϾ, �� ���Ѱ�� 1���� ���� max�� üũ
	{
		for (int k = 0; k < 4; ++k)
		{
			int nx = cur_x + dx[k];
			int ny = cur_y + dy[k];

			ans = max(ans, sum - map[nx][ny]);
		}
	}
}
void dfs(int cur_x, int cur_y, int sum, int depth)
{
	if (depth == 4)
	{
		ans = max(ans, sum);
		return;
	}
	for (int k = 0; k < 4; ++k)
	{
		int nx = dx[k] + cur_x;
		int ny = dy[k] + cur_y;

		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if (visit[nx][ny]) continue;
		
		visit[nx][ny] = true;
		dfs(nx, ny, sum + map[nx][ny], depth + 1);
		visit[nx][ny] = false;
	}
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}