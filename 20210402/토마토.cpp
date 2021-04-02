#include<iostream>
#include<queue>
#define max_n 100
using namespace std;

typedef struct
{
	int h, n, m;
}tomato;

int map[max_n + 1][max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1][max_n + 1];
int n, m, h;
int none_tomato;
int ans;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int dh[2] = {1,-1};
queue<tomato> q;
void solution();
void input();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
	
	if (none_tomato != 0) cout << -1 << '\n'; // 다 익지 못하는 상황
	else cout << ans << '\n';

	return 0;
}
void solution()
{
	while (1)
	{
		int q_size = q.size(); // q사이즈만큼만 -> 하루씩

		if (none_tomato == 0) break;
		if (q_size == 0) break;

		for (int i = 0; i < q_size; ++i)
		{
			int cur_h = q.front().h;
			int cur_x = q.front().n;
			int cur_y = q.front().m;
			q.pop();

			for (int k = 0; k < 4; ++k) // 동서남북
			{
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];
				
				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (visit[cur_h][nx][ny]) continue;
				if (map[cur_h][nx][ny] != 0) continue;

				map[cur_h][nx][ny] = 1;
				visit[cur_h][nx][ny] = true;
				q.push({ cur_h,nx,ny });
				--none_tomato;
			}

			for (int k = 0; k < 2; ++k) // 위아래
			{
				int nh = dh[k] + cur_h;

				if (nh > h || nh < 1) continue;
				if (visit[nh][cur_x][cur_y]) continue;
				if (map[nh][cur_x][cur_y] != 0) continue;

				map[nh][cur_x][cur_y] = 1;
				visit[nh][cur_x][cur_y] = true;
				q.push({ nh,cur_x, cur_y });
				--none_tomato;
			}

		}

		++ans;
	}
}
void input()
{
	cin >> m >> n >> h;
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 0) ++none_tomato; // 안익은 토마토 갯수
				else if (map[i][j][k] == 1)
				{
					visit[i][j][k] = true;
					q.push({ i,j,k });
				}
			}
		}
	}
}