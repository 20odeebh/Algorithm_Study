#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1000000001;
#define max_n 11
using namespace std;

int n;
int max_ans, min_ans;
int ary[max_n + 1];
int calc_size;
vector<int> calc; // 1+ 2- 3x 4/
void input();
void swap(int a, int b);
void pemu(int depth);
void get_ans();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	max_ans = -INF;
	min_ans = INF;

	pemu(0);

	cout << max_ans << '\n' << min_ans << '\n';
	return 0;
}
void pemu(int depth)
{
	if (depth == calc_size)
	{
		get_ans();
		return;
	}
	for (int i = depth; i < calc_size; ++i)
	{
		swap(i, depth);
		pemu(depth + 1);
		swap(i, depth);
	}

}
void get_ans()
{
	int cur_num = ary[1];

	for (int i = 0; i < calc_size; ++i)
	{
		int cur_calc = calc[i];

		switch (cur_calc)
		{
		case 1: cur_num += ary[i + 2]; break;
		case 2: cur_num -= ary[i + 2]; break;
		case 3: cur_num *= ary[i + 2]; break;
		case 4: cur_num /= ary[i + 2]; break;
		}
	}
	max_ans = max(cur_num, max_ans);
	min_ans = min(cur_num, min_ans);
}
void swap(int a, int b)
{
	int temp;
	temp = calc[a];
	calc[a] = calc[b];
	calc[b] = temp;
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> ary[i];
	for (int i = 1; i <= 4; ++i)
	{
		int num;
		cin >> num;
		for (int k = 1; k <= num; ++k)
		{
			calc.push_back(i);
		}
	}
	calc_size = calc.size();
}