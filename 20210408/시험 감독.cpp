#include<iostream>
#define max_n 1000000
using namespace std;

int N, B, C;
int ary[max_n + 1];
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> ary[i];
	}
	cin >> B >> C;

	for (int i = 1; i <= N; ++i)
	{
		ary[i] -= B;
	}
	ans += N;

	for (int i = 1; i <= N; ++i)
	{
		if (ary[i] < 1) continue;

		ans += ary[i] / C;
		int temp;
		temp = ary[i] % C;

		if (temp >= 1) ++ans;
	}

	cout << ans << '\n';

	return 0;
}