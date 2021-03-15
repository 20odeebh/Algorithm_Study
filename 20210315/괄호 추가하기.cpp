#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> num;
vector<char> oper;

void init();
int calc(int num1, int num2, char op);
int dfs(int n, int res);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	cout << dfs(0, num[0]) << '\n';
	return 0;
}
int dfs(int n, int res)
{
	if (n == N / 2) return res;

	int ret = dfs(n + 1, calc(res, num[n + 1], oper[n]));
	if (n + 2 <= N / 2)
	{
		int mid = calc(num[n + 1], num[n + 2], oper[n + 1]);
		ret = max(ret, dfs(n + 2, calc(res, mid, oper[n])));
	}
	return ret;
}
int calc(int num1, int num2, char op)
{
	if (op == '+') return num1 + num2;
	else if (op == '-') return num1 - num2;
	else return num1 * num2;
}
void init()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char temp;
		cin >> temp;
		if (i % 2 == 1) oper.push_back(temp);
		else num.push_back(temp - '0');
	}
}