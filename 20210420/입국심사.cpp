#include<iostream>
#include<vector>
#include<algorithm>
#define max_n 100000
using namespace std;

int n, m;
long long max_time, temp;
vector<long long> ans;
long long ary[max_n + 1];
void input();
void solution();

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
	}

	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';
	}
	return 0;
}
void solution()
{
	long long left = 0;
	long long right = (long long)(max_time * m);
	long long mid, sum;
	temp = right;

	while (1)
	{
		if (left > right) break;
		sum = 0;
		mid = (left + right) / 2;

		for (int i = 1; i <= n; ++i) sum += (mid / ary[i]);

		if (sum < m) left = mid + 1;
		else
		{
			temp = mid;
			right = mid - 1;
		}
	}
	ans.push_back(temp);
}
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ary[i];
		max_time = max(ary[i], max_time);
	}
}