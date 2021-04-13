#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 100
using namespace std;

vector<int> ans;
int n;
int score;
int map[max_n + 1][max_n + 1];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> worm[11];
void input();
void solution();
void play_game(int cur_x, int cur_y, int cur_move);
int get_opp(int move);
void clear_func();
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

		ans.push_back(score);

		clear_func();// map, worm 클리어
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}
void clear_func()
{
	for (int i = 1; i <= max_n; ++i)
	{
		for (int j = 1; j <= max_n; ++j)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 1; i <= 10; ++i) worm[i].clear();
}
void solution()
{
	score = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (map[i][j] == 0)
			{
				for (int k = 0; k < 4; ++k)
				{
					play_game(i, j, k);
				}
			}
		}
	}
}
void play_game(int cur_x, int cur_y, int cur_move)
{
	int sum = 0;
	int start_x = cur_x; // 출발위치
	int start_y = cur_y;
	//cout << cur_x << ", " << cur_y << ", " << cur_move << '\n';

	while (1)
	{
		
		cur_x += dx[cur_move];
		cur_y += dy[cur_move];
		
		if (cur_x < 1 || cur_y < 1 || cur_x > n || cur_y > n) //범위초과
		{
			++sum;
			cur_move = get_opp(cur_move);
		}
		else if (map[cur_x][cur_y] >= 6) // 웜홀
		{
			int nx, ny;
			if (worm[map[cur_x][cur_y]][0].first == cur_x && worm[map[cur_x][cur_y]][0].second == cur_y)
			{
				nx = worm[map[cur_x][cur_y]][1].first;
				ny = worm[map[cur_x][cur_y]][1].second;
				cur_x = nx;
				cur_y = ny;
			}
			else
			{
				nx = worm[map[cur_x][cur_y]][0].first;
				ny = worm[map[cur_x][cur_y]][0].second;
				cur_x = nx;
				cur_y = ny;
			}
		}
		else if	((start_x == cur_x && start_y == cur_y) || map[cur_x][cur_y] == -1) break;
		else if (map[cur_x][cur_y] != 0)// 1~5
		{
			switch (map[cur_x][cur_y])
			{
			case 1: 
				if (cur_move == 0) cur_move = get_opp(cur_move); 
				else if(cur_move == 1) cur_move = get_opp(cur_move);
				else if (cur_move == 2) cur_move = 1;
				else if (cur_move == 3) cur_move = 0;
				break;
			case 2: 
				if (cur_move == 0) cur_move = 1;
				else if (cur_move == 1) cur_move = get_opp(cur_move);
				else if (cur_move == 2) cur_move = get_opp(cur_move);
				else if (cur_move == 3) cur_move = 2;
				break;
			case 3: 
				if (cur_move == 0) cur_move = 3;
				else if (cur_move == 1) cur_move = 2;
				else if (cur_move == 2) cur_move = get_opp(cur_move);
				else if (cur_move == 3) cur_move = get_opp(cur_move);
				break;
			case 4: 
				if (cur_move == 0) cur_move = get_opp(cur_move);
				else if (cur_move == 1) cur_move = 0;
				else if (cur_move == 2) cur_move = 3;
				else if (cur_move == 3) cur_move = get_opp(cur_move);
				break;
			case 5: 
				if (cur_move == 0) cur_move = get_opp(cur_move);
				else if (cur_move == 1) cur_move = get_opp(cur_move);
				else if (cur_move == 2) cur_move = get_opp(cur_move);
				else if (cur_move == 3) cur_move = get_opp(cur_move);
				break;
			}
			++sum;
		}
	
		// 시작지점 or 블랙홀
	}

	score = max(sum, score);
}
int get_opp(int move)
{
	int res;
	if (move == 0) res = 2;
	else if (move == 1) res = 3;
	else if (move == 2) res = 0;
	else if (move == 3) res = 1;

	return res;
}
void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] >= 6)
			{
				worm[map[i][j]].push_back({ i,j });
			}
		}
	}
}