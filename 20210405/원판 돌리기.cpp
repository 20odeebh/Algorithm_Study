#include<iostream>
#include<utility>
#include<queue>
#define max_n 50
using namespace std;

int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int n, m, t;
int ans;
bool check;
void input();
void solution();
void turn_func(int x, int d, int k);
void bfs(int x, int y);
void avg_func();
void bfs_func();
void visit_clear();
void print();
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
	for (int i = 1; i <= t; ++i)
	{
		int x, d, k; // x���� ������ d�������� kĭ ȸ�� (0 �ð�, 1 �ݽð�)
		cin >> x >> d >> k;
		
		for (int a = 1; a <= n; ++a)
		{
			if (x * a> n) break;

			turn_func(x * a, d, k); // 1��° ����
		}
		

		check = false; // do_func ����, �״�θ� ��ձ��ϱ�

		//cout << "before\n";
		//print();

		bfs_func(); // 2��������

		if (!check) avg_func();

		//cout << "after\n";
		//print();

	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] != 0) ans += map[i][j]; // ��� ���� ��, ���䱸�ϱ�
		}
	}
}
void avg_func()
{
	int cnt = 0;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] != 0)
			{
				++cnt;
				sum += map[i][j];
			}
		}
	}
	double avg = (double)sum / cnt;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] != 0)
			{
				if ((double)map[i][j] > avg) --map[i][j];
				else if ((double)map[i][j] < avg) ++map[i][j];
			}
		}
	}

}
void bfs_func()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if(map[i][j] != 0) bfs(i, j); // 0�̾ƴϰ�, �湮��������
		}
	}
}
void bfs(int x, int y)
{
	visit_clear();

	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	int cnt = 1;
	int cur_num = map[x][y];
	while (1)
	{
		if (q.empty()) break;
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		// ���Ʒ��� �����ʰ� x
		// �¿�� �����ʰ���, �ݴ�������� �ٲ��ֱ�
		for (int k = 0; k < 4; ++k)
		{
			int nx = dx[k] + cur_x;
			int ny = dy[k] + cur_y;

			if (nx < 1 || nx > n) continue; // ���Ʒ� �����ʰ�
			if (ny < 1) ny = m;
			if (ny > m) ny = 1;
			if (visit[nx][ny]) continue;
			if (map[nx][ny] != cur_num) continue;
			
			++cnt;
			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
	if (cnt >= 2)
	{
		check = true;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (visit[i][j]) map[i][j] = 0;
			}
		}
	}
	// bfs�� ���� �����ϸ鼭 ������ ��� �����
	// �׷� ���� ������ ��� ���ϰ�, ����
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
void print()
{
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
void turn_func(int x, int d, int k)
{
	k %= m; // m�� ȸ���ϸ�, ���ڸ�
	
	deque<int> dq;

	for (int i = 1; i <= m; ++i)
	{
		dq.push_back(map[x][i]);
	}
	int temp;

	if (d == 0) // �ð�
	{
		for (int i = 1; i <= k; ++i)
		{
			temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}
	}
	else if (d == 1) // �ݽð�
	{
		for (int i = 1; i <= k; ++i) 
		{
			temp = dq.front();
			dq.pop_front();
			dq.push_back(temp);
		}
	}

	int dq_size = dq.size();

	for (int i = 0; i < dq_size; ++i)
	{
		map[x][i + 1] = dq[i];
	}

	dq.clear();
}
void input()
{
	cin >> n >> m >> t;
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}