#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#define max_n 50
using namespace std;

vector<int> ans;
int n, m;
int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,-1,1,-1,1 };
void solution();
void visit_clear();
void bfs(int x, int y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solution();
	
	int ans_size = ans.size();
	for (int i = 0; i < ans_size; ++i)
	{
		cout << ans[i] << '\n';
	}
	
	return 0;
}
void solution()
{
	while (1)
	{
		cin >> m >> n; // 행렬 반대입력
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> map[i][j]; 
			}
		}
		

		visit_clear(); // 새로운 테케마다 방문배열 정리

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					++cnt; // 섬갯수 1개씩증가
					bfs(i, j); // bfs로 방문체크
				}
			}
		}

		ans.push_back(cnt);
	}
}
void bfs(int x, int y)
{ 
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;

	while (1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; ++k)
		{
			int nx = dx[k] + cur_x;
			int ny = dy[k] + cur_y;

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (map[nx][ny] != 1)continue;
			if (visit[nx][ny]) continue;
			
			visit[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			visit[i][j] = false;
		}
	}
}