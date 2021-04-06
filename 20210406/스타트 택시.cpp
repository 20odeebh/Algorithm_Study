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
	int dis; // 시작-> 도착지점
	int taxi_dis;
}cus;
bool cmp(cus c1, cus c2) // 거리, 행, 열 순서로
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
	// 택시가 태울 승객은, 현재위치에서 가장 짧은, 같으면 행번호가 작고, 열번호가 작은 승객
	// 한 승객을 목적지로 옮기면 태워서 이동한 연료 x2 충전 (승객->목적지거리 x 2)
	// 이동하는 도중 연료 바닥나면 실패 (택시->승객 + 승객->목적지) <= 현재 보유기름
	bool check = true; // 운행을 다 못한경우 체크

	while (1)
	{
		int v_size = v.size();
		if (v_size == 0) break; // 운행완료

		for (int i = 0; i < v_size; ++i) // 택시->사람위치 거리 매번 갱신
		{
			int sx = v[i].sx;
			int sy = v[i].sy;
			v[i].taxi_dis = get_dis(taxi.first, taxi.second, sx, sy);
		}

		sort(v.begin(), v.end(), cmp); // 거리, 행, 열 순으로 정렬

		int sx, sy, ex, ey, dis, tdis;
		sx = v[0].sx;
		sy = v[0].sy;
		ex = v[0].ex;
		ey = v[0].ey;
		dis = v[0].dis;
		tdis = v[0].taxi_dis;

		if (dis == -1 || tdis == -1) // 택시->승객, 승객->목적지 도착불가능인 경우
		{
			check = false;
			break;
		}
	
		v.erase(v.begin()); // 맨앞 삭제
		
		if (energy < dis + tdis) // 기름없는경우
		{
			check = false;
			break;
		}
		else
		{
			energy = energy - (dis + tdis);
			energy += (dis) * 2; //운행 후, 거리 x2 충전

			taxi.first = ex; // 택시위치 변경
			taxi.second = ey;
		}
	}
	if (!check) energy = -1; // 운행못한경우
}
int get_dis(int sx, int sy, int ex, int ey)
{
	int res = 0;

	if (sx == ex && sy == ey) return res;// 한승객의 목적지와 다른승객의 출발지가 같은경우

	visit_clear();
	// 벽이 있으므로, bfs로 거리값구하기
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	bool is_find = false;
	
	//bfs를 통해, 큐의 크기만큼 한칸씩 이동하면서, 목적지 거리 찾는방식
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

	if (is_find) return res; // 목적지 도착가능한경우
	else return -1; // 아닌경우
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

	for (int i = 0; i < v_size; ++i) // 택시->사람위치 거리
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
		v.push_back({ sx,sy,ex,ey, dis,0}); // 시작, 도착, 거리 저장
	}

}