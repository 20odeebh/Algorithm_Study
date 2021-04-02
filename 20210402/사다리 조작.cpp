#include<iostream>
#include<algorithm>
using namespace std;

int N, M, H;
int ans;
bool visit[30 + 1][10 + 1];
void input();
void solution(int cnt, int x);
bool ladder();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	ans = 4;
	solution(0, 1);
	if (ans == 4) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
void solution(int cnt, int x)
{
	if (ans <= cnt) return;
	if (ladder())
	{
		if (ans > cnt) ans = cnt;
		return;
	}

	for (int i = x; i <= H; ++i)
	{
		for (int j = 1; j <= N - 1; ++j)
		{
			if (visit[i][j]) continue;
			else
			{
				visit[i][j] = 1;
				solution(cnt + 1, i);
				visit[i][j] = 0;
			}
		}
	}
}
bool ladder()
{
	for (int i = 1; i <= N; ++i)
	{
		int k = i;
		for (int j = 1; j <= H; ++j)
		{
			if (visit[j][k]) ++k; // 사다리 연결 돼 있으면 이동
			else if (k > 1 && visit[j][k - 1]) --k; // 아니면 밑으로
		}
		if (i != k) return false; // i번째가 i가 아니면
	}
	return true;
}
void input()
{
	cin >> N >> M >> H;

	for (int i = 1; i <= M; ++i)
	{
		int x, y;
		cin >> x >> y;
		visit[x][y] = true;
	}
}