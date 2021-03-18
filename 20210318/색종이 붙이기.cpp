#include<iostream>
#include<algorithm>
#define max_n 10
using namespace std;

int map[max_n + 1][max_n + 1];
bool visit[max_n + 1][max_n + 1];
int paper[6];
bool a;
int ans;
void init();
bool check_five(int x, int y);
bool check_four(int x, int y);
bool check_three(int x, int y);
bool check_two(int x, int y);
bool check_one(int x, int y);
void dfs(int x, int y, int cnt);
void visit_check(int x, int y, int wide, bool check);
bool end_check();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) a = true;
		}
	}

	init();

	ans = 300000;

	dfs(1, 1, 0);
	if (a == false) cout << 0 << '\n';
	else if (ans == 300000) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
void dfs(int x, int y, int cnt)
{
	if (ans < cnt) return;

	for (int i = 1; i <= 5; ++i)
	{
		if (paper[i] < 0)
		{
			return;
		}
	}
	if (end_check())
	{
		ans = min(cnt, ans);
		return;
	}


	if (map[x][y] == 1 && visit[x][y] == false)
	{

		if (check_five(x, y))
		{
			visit_check(x, y, 5, true);
			dfs(x, y + 1, cnt + 1);
			visit_check(x, y, 5, false);

		}
		if (check_four(x, y))
		{
			visit_check(x, y, 4, true);
			dfs(x, y + 1, cnt + 1);
			visit_check(x, y, 4, false);

		}
		if (check_three(x, y))
		{
			visit_check(x, y, 3, true);
			dfs(x, y + 1, cnt + 1);
			visit_check(x, y, 3, false);

		}
		if (check_two(x, y))
		{
			visit_check(x, y, 2, true);
			dfs(x, y + 1, cnt + 1);
			visit_check(x, y, 2, false);

		}
		if (check_one(x, y))
		{
			visit_check(x, y, 1, true);
			dfs(x, y + 1, cnt + 1);
			visit_check(x, y, 1, false);

		}
	}
	else
	{
		if (y > 10) dfs(x + 1, 1, cnt);
		else dfs(x, y + 1, cnt);

	}

}
bool end_check()
{
	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if (map[i][j] == 1 && visit[i][j] == false) return false;
		}
	}

	return true;
}
void visit_check(int x, int y, int wide, bool check)
{
	if (check == true) --paper[wide];
	else ++paper[wide];

	for (int i = x; i < x + wide; ++i)
	{
		for (int j = y; j < y + wide; ++j)
		{
			if (check == true) map[i][j] = 0;
			else map[i][j] = 1;
			visit[i][j] = check;
		}
	}
}
bool check_five(int x, int y)
{
	for (int i = x; i <= x + 4; ++i)
	{
		for (int j = y; j <= y + 4; ++j)
		{
			if (i > 10 || j > 10) return false;
			if (map[i][j] == 0) return false;
		}
	}

	return true;
}
bool check_four(int x, int y)
{
	for (int i = x; i <= x + 3; ++i)
	{
		for (int j = y; j <= y + 3; ++j)
		{
			if (i > 10 || j > 10) return false;
			if (map[i][j] == 0) return false;
		}
	}

	return true;
}
bool check_three(int x, int y)
{
	for (int i = x; i <= x + 2; ++i)
	{
		for (int j = y; j <= y + 2; ++j)
		{
			if (i > 10 || j > 10) return false;
			if (map[i][j] == 0) return false;
		}
	}

	return true;
}
bool check_two(int x, int y)
{
	for (int i = x; i <= x + 1; ++i)
	{
		for (int j = y; j <= y + 1; ++j)
		{
			if (i > 10 || j > 10) return false;
			if (map[i][j] == 0) return false;
		}
	}

	return true;
}
bool check_one(int x, int y)
{
	for (int i = x; i <= x; ++i)
	{
		for (int j = y; j <= y; ++j)
		{
			if (i > 10 || j > 10) return false;
			if (map[i][j] == 0) return false;
		}
	}

	return true;
}
void init()
{
	for (int i = 1; i <= 5; ++i)
	{
		paper[i] = 5;
	}
}