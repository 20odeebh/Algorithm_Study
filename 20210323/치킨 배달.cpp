#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#define max_n 50
#define max_m 13
#define INF 10000000
using namespace std;

int N, M;
vector<pair<int, int>> chicken;
int chicken_size;
vector<pair<int, int>> house;
int house_size;
bool check[max_m + 1];
int ans;
void dfs(int depth, int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int temp;
			cin >> temp;
			if (temp == 1) house.push_back(make_pair(i, j));
			if (temp == 2) chicken.push_back(make_pair(i, j));
		}
	}

	chicken_size = chicken.size();
	house_size = house.size();

	ans = INF;

	dfs(0, 0);

	cout << ans << '\n';
	return 0;
}
void dfs(int depth, int cur)
{
	if (depth == M)
	{
		int sum = 0;

		for (int k = 0; k < house_size; ++k)
		{
			int s;
			s = INF;
			for (int i = 0; i < chicken_size; ++i)
			{
				if (check[i])
				{
					int cur_x = chicken[i].first;
					int cur_y = chicken[i].second;
					s = min((abs(cur_x - house[k].first) + abs(cur_y - house[k].second)), s);
				}
			}
			sum += s;
		}

		ans = min(sum, ans);
		return;
	}

	for (int i = cur; i < chicken_size; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(depth + 1, i);
			check[i] = false;
		}
	}
}