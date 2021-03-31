#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#define max_n 100
using namespace std;

queue<pair<int, char>> q;
deque<pair<int, int>> dq;
int map[max_n + 1][max_n + 1];
int n;
int k, l;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;
void input();
void print();
int get_nextmove(int cur_move, char mission_move);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	//print();

	solution();

	cout << ans + 1 << '\n'; //끝나는 타이밍이라 +1

	return 0;
}
void solution()
{
	int cur_move = 0;
	dq.push_back({ 1,1 });
	map[1][1] = 4;

	int mission_time = 0;
	char mission_move = 'N';

	while (1)
	{
		if (mission_time == 0 && mission_move == 'N') // 첫시작
		{
			if (!q.empty())
			{
				mission_time = q.front().first;
				mission_move = q.front().second;
				q.pop();
			}
		}

		int nx = dq.back().first + dx[cur_move];
		int ny = dq.back().second + dy[cur_move];

		if (nx < 1 || ny < 1 || nx > n || ny > n) break; // 범위초과 

		if (map[nx][ny] == 0) // 빈공간 -> 꼬리자르기
		{

			map[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
			dq.push_back({ nx,ny });
			map[dq.back().first][dq.back().second] = 4;
	
		}
		else if (map[nx][ny] == 1) // 사과 -> 머리추가
		{
			dq.push_back({ nx,ny });
			map[dq.back().first][dq.back().second] = 4;
		}
		else if (map[nx][ny] == 4) break; // 머리랑 몸이 닿음
		
		++ans;

		if (mission_time != 0 && ans == mission_time)  // 첫시작이 아니고, 해당 명령시간
		{
		
			cur_move = get_nextmove(cur_move, mission_move);
		
			mission_time = 0;
			mission_move = 'N';
		}
	}
}
int get_nextmove(int cur_move, char mission_move) // 동남서북 0123
{
	int res;
	if (mission_move == 'D') res = cur_move + 1;
	else res = cur_move - 1;
	if (res > 3) res = 0;
	if (res < 0) res = 3;

	return res;
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}
void input()
{
	cin >> n;
	cin >> k;
	
	for (int i = 1; i <= k; ++i)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> l;

	for (int i = 1; i <= l; ++i)
	{
		int a;
		char b;
		cin >> a >> b;
		q.push({ a,b });
	}
}