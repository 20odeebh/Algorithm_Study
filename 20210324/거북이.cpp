#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#define max_n 500
using namespace std;
int dx[4] = {-1, 0, 1,0};
int dy[4] = {0, 1,0,-1};
string order;
vector<int> ans;
int max_x, max_y, min_x, min_y;

int get_next(char ch, int cur);
int get_opp(int cur);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> order;
		solution();
		ans.push_back((max_x - min_x) * (max_y - min_y));
		//cout << max_x << ", " << max_y << ", " << min_x << ", " << min_y << '\n';

	}

	int ans_size = ans.size();
	for(int i = 0; i < ans_size; ++i)
	{
		cout << ans[i] << '\n';

	}
	return 0;
}
void solution()
{
	int cur_x = 0;
	int cur_y = 0;
	int cur_move = 0;
	int order_len = order.length();
	max_x = max_y = min_x = min_y = 0;

	for (int i = 0; i < order_len; ++i)
	{
		char cur_order = order[i];
		if (cur_order == 'R' || cur_order == 'L') cur_move = get_next(cur_order, cur_move);
		else if (cur_order == 'F')
		{
			cur_x += dx[cur_move];
			cur_y += dy[cur_move];
		}
		else if (cur_order == 'B')
		{
			int temp_move = get_opp(cur_move);
			cur_x += dx[temp_move];
			cur_y += dy[temp_move];
		}
		max_x = max(cur_x, max_x);
		max_y = max(cur_y, max_y);
		min_x = min(cur_x, min_x);
		min_y = min(cur_y, min_y);
	}
}
int get_opp(int cur)
{
	int res = -1;
	if (cur == 1) res = 3;
	else if (cur == 2) res = 0;
	else if (cur == 3) res = 1;
	else if (cur == 0) res = 2;

	return res;
}
int get_next(char ch, int cur)
{
	int res = cur;

	if (ch == 'R') res += 1;
	else if (ch == 'L') res -= 1;

	if (res == -1) res = 3;
	else if (res == 4) res = 0;

	return res;
}