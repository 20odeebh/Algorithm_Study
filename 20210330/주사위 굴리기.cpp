#include<iostream>
#include<vector>
#define max_n 20
using namespace std;

int n, m;
int x, y;
int t;
int ary[7];
vector<int> ans;
int map[max_n + 1][max_n + 1];
void input();
int get_opp(int num);
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}
void solution()
{

	// ¹Ø 6 À§ 1 ¿À¸¥ 3 ¿Þ 4 ºÏÂÊ 2 ³²ÂÊ 5 °íÁ¤
	// ¿òÁ÷ÀÏ¶§ ¸¶´Ù °ª ¹Ù²ãÁÜ

	for(int i = 1; i <= t; ++i)
	{
		int order;
		cin >> order;
		int temp_ary[7] = {0,};

		if (order == 1) // µ¿
		{
			if (y + 1 > m) continue;
			++y;
			temp_ary[1] = ary[4];
			temp_ary[2] = ary[2];
			temp_ary[3] = ary[1];
			temp_ary[4] = ary[6];
			temp_ary[5] = ary[5];
			temp_ary[6] = ary[3];
		}
		else if (order == 2) // ¼­
		{
			if (y - 1 < 1) continue;
			--y;
			temp_ary[1] = ary[3];
			temp_ary[2] = ary[2];
			temp_ary[3] = ary[6];
			temp_ary[4] = ary[1];
			temp_ary[5] = ary[5];
			temp_ary[6] = ary[4];
		}
		else if (order == 3) // ºÏ
		{
			if (x - 1 < 1) continue;
			--x;
			temp_ary[1] = ary[5];
			temp_ary[2] = ary[1];
			temp_ary[3] = ary[3];
			temp_ary[4] = ary[4];
			temp_ary[5] = ary[6];
			temp_ary[6] = ary[2];
		}
		else if (order == 4) // ³²
		{
			if (x + 1 > n) continue;
			++x;
			temp_ary[1] = ary[2];
			temp_ary[2] = ary[6];
			temp_ary[3] = ary[3];
			temp_ary[4] = ary[4];
			temp_ary[5] = ary[1];
			temp_ary[6] = ary[5];
		}
		if (map[x][y] == 0)
		{
			map[x][y] = temp_ary[6];
		}
		else
		{
			temp_ary[6] = map[x][y];
			map[x][y] = 0;
		}
		for (int i = 1; i <= 6; ++i) ary[i] = temp_ary[i];
		ans.push_back(ary[1]);
	}
}
void input()
{
	cin >> n >> m >> x >> y >> t;
	++x;
	++y;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
		}
	}
}