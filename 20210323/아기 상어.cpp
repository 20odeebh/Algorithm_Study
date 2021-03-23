#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#define max_n 20

using namespace std;
typedef struct {
	int cur_x, cur_y;
	int value;
	int move;
	int eaten;
}shark;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;
int map[max_n + 1][max_n + 1];
void solution();
bool visit[max_n + 1][max_n + 1];
shark s;
bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int>p2)
{
	if (p1.second < p2.second) return true;
	else if (p1.second == p2.second)
	{
		if (p1.first.first < p2.first.first) return true;
		else if (p1.first.first == p2.first.first)
		{
			if (p1.first.second < p2.first.second) return true;
			else return false;
		}
		else return false;
	}
	else return false;

}
void init();
void Print();
void visit_clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	init();

	solution();
	cout << s.move << '\n';
	return 0;
}
void solution()
{
	queue<pair<pair<int, int>, int>> q;

	s.value = 2;
	while (1)
	{
		vector<pair<pair<int, int>, int>> able;

		q.push(make_pair(make_pair(s.cur_x, s.cur_y), 0));
		visit_clear();
		while (1)
		{

			if (q.empty()) break;
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dis = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
				if (visit[nx][ny]) continue;
				if (map[nx][ny] > s.value) continue;


				if (map[nx][ny] != 0 && map[nx][ny] < s.value)
				{
					able.push_back(make_pair(make_pair(nx, ny), dis + 1));
				}
				q.push(make_pair(make_pair(nx, ny), dis + 1));
				visit[nx][ny] = true;
			}
		}
		if (able.size() == 0) break;


		sort(able.begin(), able.end(), compare);

		int able_size = able.size();

		int eat_x = able[0].first.first;
		int eat_y = able[0].first.second;
		int dis = able[0].second;

		map[eat_x][eat_y] = 0;
		s.cur_x = eat_x;
		s.cur_y = eat_y;
		s.move += dis;
		s.eaten += 1;
		if (s.eaten == s.value)
		{
			s.eaten = 0;
			s.value += 1;
		}
		able.clear();
		map[s.cur_x][s.cur_y] = 9;
		//Print();
		map[s.cur_x][s.cur_y] = 0;
	}
}
void visit_clear()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			visit[i][j] = false;
		}
	}
}
void init()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int temp;
			cin >> temp;
			if (temp == 9)
			{
				s.cur_x = i;
				s.cur_y = j;
				map[i][j] = 0;
				continue;
			}
			map[i][j] = temp;
		}
	}
}
void Print()
{
	cout << "\n========\n";
	cout << "move : " << s.move << '\n';
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}