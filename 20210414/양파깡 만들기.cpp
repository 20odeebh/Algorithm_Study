#include<iostream>
#include<vector>
#define max_n 30
#define INF 999999999
using namespace std;
typedef struct
{
	int sum, sx, sy, ex, ey;
}yang;
yang ans[max_n + 1];
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int n, m;
void input();
void solution();
int get_taste(int sx, int sy, int ex, int ey);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	
	solution();

	bool check = true;
	for (int i = 1; i <= m; ++i)
	{
		if (ans[i].sum == -INF)
		{
			check = false;
			break;
		}
	}

	if (check)
	{
		for (int i = 1; i <= m; ++i)
		{
			cout << ans[i].sum << ' ' << ans[i].sx << ' ' << ans[i].sy << ' ' << ans[i].ex << ' ' << ans[i].ey << '\n';
		}
	}
	else cout << 0;
	return 0;
}
void solution()
{
	for (int i = 1; i <= m; ++i)
	{
		ans[i].sum = -INF;
		for (int k = 2; k <= 30; ++k) // x¿ë
		{
			for (int k2 = 2; k2 <= 30; ++k2) //y¿ë
			{
				for (int x = 1; x <= n; ++x)
				{
					for (int y = 1; y <= n; ++y)
					{
						int sx, sy, ex, ey;
						sx = x;
						sy = y;
						ex = x + k;
						ey = y + k2;

						int sum = get_taste(sx, sy, ex, ey);
						if (sum == -1) continue;
						if (sum > ans[i].sum)
						{
							ans[i] = { sum,sx,sy,ex,ey };
						}
					}

				}
			}
		}

		for (int k = ans[i].sx; k <= ans[i].ex; ++k)
		{
			visit[k][ans[i].sy] = true;
			visit[k][ans[i].ey] = true;
		}
		for (int k = ans[i].sy; k <= ans[i].ey; ++k)
		{
			visit[ans[i].sx][k] = true;
			visit[ans[i].ex][k] = true;
		}
	}
}
int get_taste(int sx, int sy, int ex, int ey)
{
	int res = -1;
	if (ex > n || ey > n) return res;
	int sum = 0;
	
	for (int i = sx; i <= ex; ++i)
	{
		if (visit[i][sy]) return res;
		sum += map[i][sy];
	}
	for (int i = sx; i <= ex; ++i)
	{
		if (visit[i][ey]) return res;
		sum += map[i][ey];
	}
	for (int i = sy; i <= ey; ++i)
	{
		if (visit[sx][i]) return res;
		sum += map[sx][i];
	}
	for (int i = sy; i <= ey; ++i)
	{
		if (visit[ex][i]) return res;
		sum += map[ex][i];
	}
	sum -= map[sx][sy];
	sum -= map[sx][ey];
	sum -= map[ex][sy];
	sum -= map[ex][ey];
	res = sum;
	return res;
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}