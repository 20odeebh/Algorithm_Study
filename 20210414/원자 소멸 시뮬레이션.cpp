#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct 
{
	int x, y, move, energy;
	bool alive;
}ele;
vector<int> ans;
int n;
int dx[4] = {0,0,-1,1};
int dy[4] = { 1,-1,0,0 };
int map[4001][4001];
vector<ele> v;
void input();
void print();
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		input();
		
		solution();
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}
	return 0;
}
void solution()
{
	int sum = 0;
	
	int v_size = v.size();
	while (1)
	{
		bool check = true;
		
		for (int i = 0; i < v_size; ++i) // 다 죽었으면 끝
		{
			if (v[i].alive)
			{
				check = false;
				break;
			}
		}
		if (check) break;
		for (int i = 0; i < v_size; ++i) 
		{
			ele cur = v[i];

			int nx = cur.x + dx[cur.move];
			int ny = cur.y + dy[cur.move];

			if (nx < 1 || ny < 1 || nx > 4000 || ny > 4000) cur.alive = false; // 범위 밖 나간것도 죽은거로 처리
			else if (cur.alive) // 살아있으면, 맵에 현재위치 +1, 좌표이동
			{
				cur.x = nx;
				cur.y = ny;
				++map[nx][ny];
			}
			v[i] = cur;
		}
		
		for (int i = 0; i < v_size; ++i)
		{
			ele cur = v[i];
			if (map[cur.x][cur.y] > 1) // 한 위치에 2개이상 있으면
			{
				for (int j = 0; j < v_size; ++j)
				{
					if (v[j].alive && v[i].x == v[j].x && v[i].y == v[j].y) // 2개이상위치에있는 원소
					{
						v[j].alive = false;
						sum += v[j].energy;
					}
				}
			}
			map[cur.x][cur.y] = 0; // 원자 맵처리 다시 0으로
		}
	}

	ans.push_back(sum);
	v.clear();
}
void print() 
{
	int v_size = v.size();
	for (int i = 0; i < v_size; ++i)
	{
		cout << v[i].x << ", " << v[i].y << ", " << v[i].move << ", " << v[i].energy << '\n';
	}
	cout << '\n';
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x, y, move, energy;
		cin >> x >> y >> move >> energy;
		v.push_back({ 2*(x+1000),2*(y+1000),move,energy, true }); // 음수처리 +1000, 0.5값 계산처리위해 *2로 좌표처리
	}
}