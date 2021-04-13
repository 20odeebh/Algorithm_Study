#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


typedef struct
{
	int x, y, life, time;
}cell;
struct cmp
{
	bool operator()(cell c1, cell c2)
	{
		return c1.life < c2.life;
	}
};
priority_queue<cell, vector<cell>, cmp> pq;
vector<int> ans;
int map[701][701]; // 0,0기준 k=300 -300,  50,50기준 k=350 -> 350 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m, k;
int sx, sy;
bool visit[701][701];
void clear_func();
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

		ans.push_back(pq.size());

		clear_func();
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
	queue<cell> q;
	for (int i = 1; i <= k; ++i)
	{
		int pq_size = pq.size();
		for (int j = 0; j < pq_size; ++j)
		{
			cell cur = pq.top();
			pq.pop();

			++cur.time;
			if (cur.life == cur.time - 1)
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = cur.x + dx[k];
					int ny = cur.y + dy[k];

					if (visit[nx][ny]) continue;
					visit[nx][ny] = true;
					q.push({ nx,ny,cur.life, 0 });
				}
				// 번식
				//q.push(cur);
			}
			if (cur.life*2 <= cur.time) continue; //죽게
			else q.push(cur); // time 만 증가
		}
		int q_size = q.size();
		for (int j = 0; j < q_size; ++j)
		{
			pq.push(q.front());
			q.pop();
		}

		//print();
	}
	
}
void print()
{
	cout << '\n';

	queue<cell> q;
	int pq_size = pq.size();
	
	for (int i = 0; i < pq_size; ++i)
	{
		cell cur = pq.top();
		pq.pop();
		cout << cur.x << ", " << cur.y << ", " << cur.life << ", " << cur.time << '\n';
		q.push(cur);
	}
	int q_size = q.size();
	for (int j = 0; j < q_size; ++j)
	{
		pq.push(q.front());
		q.pop();
	}
}
void clear_func()
{
	while (1)
	{
		if (pq.empty()) break;
		pq.pop();
	}
	for (int i = 0; i <= 700; ++i)
	{
		for (int j = 0; j <= 700; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void input()
{
	cin >> n >> m >> k;
	sx = sy = 300;
	n += sx;
	m += sy;
	for (int i = sx; i < n; ++i)
	{
		for(int j = sy; j < m; ++j)
		{
			int num;
			cin >> num;
			if (num != 0)
			{
				pq.push({ i,j,num,0 });
				visit[i][j] = true;
			}
		}
	}
}