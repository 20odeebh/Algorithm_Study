#include<iostream>
#include<queue>
#include<utility>
#define INF 999999999
#define max_n 50
using namespace std;

int n, m;
int ans;
pair<int, int> s;
pair<int, int> e;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[max_n + 1][max_n + 1]; // . : 0 / * : 1 / X : -1 / D : 9 / S : 4
int water[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
void input();
void solution();
void water_func();
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//1. water에 각 시간별 물을 저장
	//2. 고슴도치 움직이면서 자신의 시간과 water시간 비교하면서 bfs

	input();

	solution();
	
	ans = map[e.first][e.second];

	//print();

	if (ans == INF) cout << "KAKTUS\n";
	else cout << ans - 1 << '\n';

	return 0;
}
void solution()
{
	water_func();


	queue<pair<int, int>> q;
	q.push(s);
	visit[s.first][s.second] = true;
	map[s.first][s.second] = 1;
	map[e.first][e.second] = INF;

	while(1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		int cur_time = map[cur_x][cur_y];
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + cur_x;
			int ny = dy[k] + cur_y;

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] == -1) continue;
			if (water[nx][ny] != 0 && water[nx][ny] <= cur_time + 1)
			{
				if (map[nx][ny] == INF) map[nx][ny] = cur_time + 1;
				else continue;
			}
			visit[nx][ny] = true;
			q.push({ nx,ny });
			map[nx][ny] = cur_time + 1;
		}
	}
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "\n\n";

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << water[i][j] << ' ';
		}
		cout << '\n';
	}
}
void water_func()
{
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (water[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}
	while (1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + cur_x;
			int ny = dy[k] + cur_y;

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (water[nx][ny] != 0) continue;
			if (nx == e.first && ny == e.second) continue;

			water[nx][ny] = water[cur_x][cur_y] + 1;
			q.push({ nx,ny });
		}
	}

}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == '.') map[i][j] = 0;
			else if (ch == '*')
			{
				//map[i][j] = 1;
				water[i][j] = 1;
			}
			else if (ch == 'X')
			{
				map[i][j] = -1;
				water[i][j] = -1;
			}
			else if (ch == 'D')
			{
				e = { i,j };
			}
			else if (ch == 'S') s = { i,j };
		}
	}
}