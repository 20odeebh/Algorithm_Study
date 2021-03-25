#include<iostream>
#include<algorithm>
#include<cmath>
#define max_n 500
using namespace std;
int x, y;
int ary[max_n + 1];
int ans;
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;
	for (int i = 1; i <= y; ++i)
	{
		cin >> ary[i];
	}
	solution();

	cout << ans << '\n';
	return 0;
}
void solution()
{
	for (int i = 2; i < y; ++i)
	{
		int l_max = 0;
		int r_max = 0;
		for (int k = i; k >= 1; --k)
		{
			l_max = max(l_max, ary[k]);
		}
		for (int k = i; k <= y; ++k)
		{
			r_max = max(r_max, ary[k]);
		}
		int temp = min(r_max, l_max);
		ans += abs(temp - ary[i]);
	}
}