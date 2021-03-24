#include<iostream>
#include<queue>
using namespace std;

char map[12 + 1][6 + 1]; //1,1부터 사용
int ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visit[12 + 1][6 + 1];
int cnt;
void print();
void gravity();
void bfs(int i, int j);
void visit_clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 6; ++j)
			cin >> map[i][j];



	//print();

	while (1) {
		for (int i = 1; i <= 12; ++i)
		{
			for (int j = 1; j <= 6; ++j)
			{
				if (map[i][j] != '.')
				{
					bfs(i, j);
					visit_clear();
				}
			}
		}
		if (cnt > 0) {
			++ans;
			cnt = 0;
			gravity();
		}
		else break;
	}

	cout << ans << '\n';

	//print();
	return 0;
}
void visit_clear()
{
	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 6; ++j) visit[i][j] = false;
}
void  bfs(int i, int j)
{
	queue<pair<int, int>> q;

	q.push(make_pair(i, j));
	visit[i][j] = true;
	vector<pair<int, int>> v;

	v.push_back(make_pair(i, j));

	while (1)
	{
		if (q.empty())
		{
			int size = v.size();
			if (size >= 4)
			{
				for (int i = 0; i < size; ++i)
				{
					map[v[i].first][v[i].second] = '.';
				}
				++cnt;
			}
			v.clear();

			break;
		}

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > 12 || ny > 6) continue; // 범위초과
			if (map[nx][ny] != map[x][y]) continue;
			if (visit[nx][ny]) continue;

			visit[nx][ny] = true;
			v.push_back(make_pair(nx, ny));
			q.push(make_pair(nx, ny));
		}
	}

}
void gravity()
{
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 12; j > 0; --j)
		{
			if (map[j][i] == '.')
			{
				int k = j;
				int start = -1;

				for (; k > 0; --k)
				{
					if (map[k][i] != '.')
					{
						start = k;
						break;
					}
				}
				if (start == -1) continue; // 못찾았으면
				map[j][i] = map[start][i];
				map[start][i] = '.';
			}
		}
	}
}
void print()
{

	cout << "\n-------------\n";
	for (int i = 1; i <= 12; ++i) {
		for (int j = 1; j <= 6; ++j)
			cout << map[i][j];
		cout << '\n';

	}
}