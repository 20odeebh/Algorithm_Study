#include<iostream>
#include<vector>
#include<utility>
#define max_n 50

using namespace std;
typedef struct
{
	int x;
	int y;
	int cur;
}cur;

int map[max_n + 1][max_n + 1];
int dx[4] = {-1,0,1,0}; // �ϵ�����
int dy[4] = {0,1,0,-1};
int n, m;
cur c;
int ans;

void input();
void solution();
int get_next(int cur);

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
	// 1. ������ġ û��
	// 2. ���ʿ� û�� �������� -> ȸ��func -> ��ĭ���� û��
	// 3. ���ʿ� û�� ����x -> ȸ��func
	// 4. 4���� ��� û���Ұ� ���ٸ�, ����
	// 5. 4���� ��� û���Ұ� ����, ���� �� �� �� ������ ����
	map[c.x][c.y] = 4;
	++ans;
	int cnt = 0;
	int nx, ny;
	while (1)
	{
		if (cnt == 4)
		{
			int back = get_next(get_next(c.cur));
			nx = c.x + dx[back];
			ny = c.y + dy[back];
			if (nx < 1 || ny < 1 || nx > n || ny > m || map[nx][ny] == 1) break;
			c.x = nx;
			c.y = ny;
			cnt = 0;
		}
		c.cur = get_next(c.cur);
		nx = c.x + dx[c.cur];
		ny = c.y + dy[c.cur];
		++cnt;
		if (nx < 1 || ny < 1 || nx > n || ny > m) continue; // ���̰ų�
		if (map[nx][ny] != 0) continue; // û���ҰԾ��ų�

		map[nx][ny] = 4;
		c.x = nx;
		c.y = ny;
		++ans;
		cnt = 0;
	}
}
int get_next(int cur)
{
	cur -= 1;
	if (cur == -1) cur = 3;
	return cur;
}
void input()
{
	cin >> n >> m;
	int x, y, temp;
	cin >> x >> y >> temp;
	c.x = x + 1;
	c.y = y + 1;
	c.cur = temp;

	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}