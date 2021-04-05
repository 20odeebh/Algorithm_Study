#include<iostream>
#include<algorithm>
#define max_n 15
using namespace std;

int n, ans;
int t[max_n + 1];
int p[max_n + 1];
bool visit[max_n + 1];
void input();
void dfs(int cur_day, int sum);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	dfs(1, 0);

	cout << ans << '\n';

	return 0;
}
void dfs(int cur_day, int sum)
{
	if (cur_day >= n + 1) //tn이 1일인걸 고려해 n+1
	{
		ans = max(ans, sum);
		return;
	}
	
	if (cur_day + t[cur_day] <= n + 1) dfs(cur_day + t[cur_day], sum + p[cur_day]); // 예약

	if (cur_day + 1 <= n + 1) dfs(cur_day + 1, sum); // 예약안하고 넘어감
}
void input()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> p[i];
	}
}