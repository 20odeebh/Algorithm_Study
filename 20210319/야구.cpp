#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define max_n 50
using namespace std;

int N;
int score[max_n + 1][10];
vector<int> ary;
vector<int> temp;
int ans;
void swap(int a, int b);
void init();
void permu(int cur);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	permu(0);

	cout << ans << '\n';
	return 0;
}
void solution()
{
	int out_cnt = 0;
	int sum = 0;
	int num = 0;
	int cur_num = 0;
	int ground[10];

	for (int i = 1; i <= N; ++i)
	{
		for (int i = 1; i <= 9; ++i) ground[i] = 0;
		out_cnt = 0;

		while (1)
		{
			if (out_cnt == 3) break;
			int cur = temp[cur_num];
			int res = score[i][cur];
			++cur_num;
			if (cur_num == 9) cur_num = 0;

			if (res == 0)
			{
				++out_cnt;
			}
			else if (res == 1)
			{
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];

				ground[1] = 1;
			}
			else if (res == 2)
			{
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];
				ground[2] = 1;
				ground[1] = 0;
			}
			else if (res == 3)
			{
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];
				for (int i = 9; i >= 1; --i) ground[i] = ground[i - 1];
				ground[3] = 1;
				ground[2] = 0;
				ground[1] = 0;
			}
			else // 홈런
			{
				++sum;
				for (int i = 1; i <= 9; ++i)
				{
					if (ground[i] == 1) ++sum;
					ground[i] = 0;
				}
			}

			for (int i = 9; i >= 4; --i)
			{
				if (ground[i] == 1) ++sum;
				ground[i] = 0;
			}
		}
		// 점수
	}
	ans = max(ans, sum);
}
void init()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			cin >> score[i][j];
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (i == 1) continue;
		ary.push_back(i);
	}
}
void permu(int cur)
{
	if (cur == 7)
	{
		for (int i = 0; i < 3; ++i) temp.push_back(ary[i]);
		temp.push_back(1);
		for (int i = 3; i < 8; ++i) temp.push_back(ary[i]);

		solution();

		temp.clear();
		return;
	}

	for (int i = cur; i < 8; ++i)
	{
		swap(i, cur);
		permu(cur + 1);
		swap(i, cur);
	}

}
void swap(int a, int b)
{
	int temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}