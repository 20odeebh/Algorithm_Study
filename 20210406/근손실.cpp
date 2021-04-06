#include<iostream>
#define max_n 8
using namespace std;
int kit[max_n + 1];
int n, k;
int ans;
void input();
void swap(int a, int b);
void permu(int cur);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 순열을 통해 모든 kit 순서로 cur_weight + kit[i] - k 가 음수이면 정답x

	input();
	permu(1);
	cout << ans << '\n';

	return 0;
}
void permu(int cur)
{
	if (cur == n)
	{
		bool check = true;
		int cur_w = 500;

		for (int i = 1; i <= n; ++i)
		{
			cur_w += kit[i];
			cur_w -= k;

			if (cur_w < 500)
			{
				check = false;
				break;
			}
		}
		if (check) ++ans;

		return;
	}

	for (int i = cur; i <= n; ++i)
	{
		swap(i, cur);
		permu(cur+1);
		swap(i, cur);
	}
}
void swap(int a, int b)
{
	int temp;
	temp = kit[a];
	kit[a] = kit[b];
	kit[b] = temp;
}
void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> kit[i];
}