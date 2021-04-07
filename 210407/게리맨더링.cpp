#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num[15];
vector<int> area[15];
vector<int> red;
int Min = 999999999;

int blue_check(vector<int> blue, int visited[15])
{
	queue<int> q;
	q.push(blue[0]);
	visited[blue[0]] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < area[now].size(); i++)
		{
			int next = area[now][i];

			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
				cnt++;
			}
		}
	}

	if (cnt == blue.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int red_check(int visited[15])
{
	queue<int> q;
	q.push(red[0]);
	visited[red[0]] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < area[now].size(); i++)
		{
			int next = area[now][i];

			if (visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
				cnt++;
			}
		}
	}

	if (cnt == red.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void combination(int idx, int cnt, int finish)
{
	if (cnt == finish)
	{
		vector<int> blue;
		int red_visited[15] = { 0 };
		int blue_visited[15] = { 0 };
		int sum1 = 0;
		int sum2 = 0;

		for (int i = 0; i < red.size(); i++)
		{
			blue_visited[red[i]] = 1;
			sum1 += num[red[i]];
		}

		for (int i = 1; i <= N; i++)
		{
			if (blue_visited[i] == 0)
			{
				red_visited[i] = 1;
				blue.push_back(i);
				sum2 += num[i];
			}
		}

		if (red_check(red_visited) == 1)
		{
			if (blue_check(blue, blue_visited) == 1)
			{
				Min = min(Min, abs(sum1 - sum2));
			}
		}

		return;
	}

	for (int i = idx; i <= N; i++)
	{
		red.push_back(i);
		combination(i + 1, cnt + 1, finish);
		red.pop_back();
	}
}

int main(void)
{
	//    freopen("B17471_input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	for (int from = 1; from <= N; from++)
	{
		int M;
		cin >> M;

		for (int i = 1; i <= M; i++)
		{
			int to;
			cin >> to;

			area[from].push_back(to);
			area[to].push_back(from);
		}
	}

	for (int i = 1; i <= N / 2; i++)
	{
		combination(1, 0, i);
	}

	if (Min == 999999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}

	return 0;
}
