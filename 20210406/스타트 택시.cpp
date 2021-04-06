#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define max_n 20
using namespace std;
typedef struct
{
	int sx;
	int sy;
	int ex;
	int ey;
	int dis; // ����-> ��������
	int taxi_dis;
}cus;
bool cmp(cus c1, cus c2) // �Ÿ�, ��, �� ������
{
	if (c1.taxi_dis == c2.taxi_dis)
	{
		if (c1.sx == c2.sx) return c1.sy < c2.sy;
		else return c1.sx < c2.sx;
	}
	else return c1.taxi_dis < c2.taxi_dis;
}
bool visit[max_n + 1][max_n + 1];
int dx[4] = {0,0,-1,1};
int dy[4] = { -1,1,0,0 };
vector<cus> v;
int n, m, energy;
pair<int, int> taxi;
int map[max_n + 1][max_n + 1];
void input();
void solution();
void print();
void visit_clear();
int get_dis(int sx, int sy, int ex, int ey);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	cout << energy << '\n';

	return 0;
}
void solution()
{
	// �ýð� �¿� �°���, ������ġ���� ���� ª��, ������ ���ȣ�� �۰�, ����ȣ�� ���� �°�
	// �� �°��� �������� �ű�� �¿��� �̵��� ���� x2 ���� (�°�->�������Ÿ� x 2)
	// �̵��ϴ� ���� ���� �ٴڳ��� ���� (�ý�->�°� + �°�->������) <= ���� �����⸧
	bool check = true; // ������ �� ���Ѱ�� üũ

	while (1)
	{
		int v_size = v.size();
		if (v_size == 0) break; // ����Ϸ�

		for (int i = 0; i < v_size; ++i) // �ý�->�����ġ �Ÿ� �Ź� ����
		{
			int sx = v[i].sx;
			int sy = v[i].sy;
			v[i].taxi_dis = get_dis(taxi.first, taxi.second, sx, sy);
		}

		sort(v.begin(), v.end(), cmp); // �Ÿ�, ��, �� ������ ����

		int sx, sy, ex, ey, dis, tdis;
		sx = v[0].sx;
		sy = v[0].sy;
		ex = v[0].ex;
		ey = v[0].ey;
		dis = v[0].dis;
		tdis = v[0].taxi_dis;

		if (dis == -1 || tdis == -1) // �ý�->�°�, �°�->������ �����Ұ����� ���
		{
			check = false;
			break;
		}
	
		v.erase(v.begin()); // �Ǿ� ����
		
		if (energy < dis + tdis) // �⸧���°��
		{
			check = false;
			break;
		}
		else
		{
			energy = energy - (dis + tdis);
			energy += (dis) * 2; //���� ��, �Ÿ� x2 ����

			taxi.first = ex; // �ý���ġ ����
			taxi.second = ey;
		}
	}
	if (!check) energy = -1; // ������Ѱ��
}
int get_dis(int sx, int sy, int ex, int ey)
{
	int res = 0;

	if (sx == ex && sy == ey) return res;// �ѽ°��� �������� �ٸ��°��� ������� �������

	visit_clear();
	// ���� �����Ƿ�, bfs�� �Ÿ������ϱ�
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	bool is_find = false;
	
	//bfs�� ����, ť�� ũ�⸸ŭ ��ĭ�� �̵��ϸ鼭, ������ �Ÿ� ã�¹��
	while (1)
	{
		int q_size = q.size();
		if (q_size == 0) break;

		for (int i = 0; i < q_size; ++i)
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = dx[k] + x;
				int ny = dy[k] + y;
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (visit[nx][ny]) continue;
				if (map[nx][ny] == 1) continue;

				if (nx == ex && ny == ey)
				{
					is_find = true;
					break;
				}
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
			if (is_find) break;
		}
		++res;
		if (is_find) break;
	}

	while (1)
	{
		if (q.empty()) break;
		q.pop();
	}

	if (is_find) return res; // ������ ���������Ѱ��
	else return -1; // �ƴѰ��
}
void visit_clear()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void print()
{
	int v_size = v.size();

	for (int i = 0; i < v_size; ++i) // �ý�->�����ġ �Ÿ�
	{
		int sx = v[i].sx;
		int sy = v[i].sy;
		int ex = v[i].ex;
		int ey = v[i].ey;
		int dis = v[i].dis;
		int tdis = v[i].taxi_dis;

		cout << sx << ", " << sy << ", " << ex << ", " << ey << ", " << dis << ", " << tdis << '\n';
	}
}
void input()
{
	cin >> n >> m >> energy;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	taxi.first = x;
	taxi.second = y;

	for (int i = 1; i <= m; ++i)
	{
		int sx, sy, ex, ey, dis;
		cin >> sx >> sy >> ex >> ey;
		dis = get_dis(sx, sy, ex, ey);
		v.push_back({ sx,sy,ex,ey, dis,0}); // ����, ����, �Ÿ� ����
	}

}