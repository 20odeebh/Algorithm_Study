#include<iostream>
#include<algorithm>
#include<vector>
#define max_n 20
#define INF 20000000
using namespace std;

int A[max_n + 1][max_n + 1];
int map[max_n + 1][max_n + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int ans;
void input();
void solution();
bool check_area(int i, int j, int d1, int d2);
void map_clear();
void print();
void divide_map(int x, int y, int d1, int d2);
bool is_five();
void get_ans();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ans = INF;

	input();

	solution();

	cout << ans << '\n';
	return 0;
}
void solution()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int d1 = 1; d1 <= n; ++d1)
			{
				for (int d2 = 1; d2 <= n; ++d2)
				{
					if (check_area(i, j, d1, d2) == false) continue;
					divide_map(i, j, d1, d2);
					//if (i == 4 && j == 3 && d1 == 1 && d2 == 1) print();
					if (is_five() == false) continue;
					get_ans();
				}
			}
		}
	}
}
void get_ans()
{
	vector<int> temp;

	for (int i = 0; i < 5; ++i)
	{
		temp.push_back(0);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int idx;
			if (map[i][j] == 1) idx = 1;
			if (map[i][j] == 2) idx = 2;
			if (map[i][j] == 3) idx = 3;
			if (map[i][j] == 4) idx = 4;
			if (map[i][j] == 0 || map[i][j] == 5) idx = 5;
			temp[idx - 1] += A[i][j];
		}
	}
	sort(temp.begin(), temp.end());
	ans = min(ans, temp[4] - temp[0]);
	temp.clear();
}
bool is_five()
{
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	bool check4 = false;
	bool check5 = false;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (map[i][j] == 1) check1 = true;
			else if (map[i][j] == 2) check2 = true;
			else if (map[i][j] == 3) check3 = true;
			else if (map[i][j] == 4) check4 = true;
			else if (map[i][j] == 5) check5 = true;
		}
	}
	return check1 && check2 && check3 && check4 && check5;
}
void divide_map(int x, int y, int d1, int d2)
{
	int s_x = 1;
	int e_x = x + d1;
	int s_y = 1;
	int e_y = y;

	int temp_num = 1;
	for (int i = s_x; i < e_x; ++i)
	{
		for (int j = s_y; j <= e_y; ++j)
		{
			if (map[i][j] != 0) break;
			map[i][j] = temp_num;
		}
	}
	s_x = 1;
	e_x = x + d2;
	s_y = y;
	e_y = n;
	++temp_num;
	for (int i = s_x; i <= e_x; ++i)
	{
		for (int j = e_y; j > s_y; --j)
		{
			if (map[i][j] != 0) break;
			map[i][j] = temp_num;
		}
	}
	s_x = x + d1;
	e_x = n;
	s_y = 1;
	e_y = y - d1 + d2;
	++temp_num;
	for (int i = e_x; i >= s_x; --i)
	{
		for (int j = s_y; j < e_y; ++j)
		{
			if (map[i][j] != 0) break;
			map[i][j] = temp_num;
		}
	}
	s_x = x + d2;
	e_x = n;
	s_y = y - d1 + d2;
	e_y = n;
	++temp_num;
	for (int i = e_x; i > s_x; --i)
	{
		for (int j = e_y; j >= s_y; --j)
		{
			if (map[i][j] != 0) break;
			map[i][j] = temp_num;
		}
	}
}
void print()
{
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}
bool check_area(int x, int y, int d1, int d2)
{
	int s_x = x;
	int e_x = x + d1 + d2;
	int s_y = y - d1;
	int e_y = y + d2;
	if (s_x < 1 || s_y < 1 || e_x > n || e_y > n) return false;
	map_clear();

	int temp_x = x;
	int temp_y = y;
	int l_x = x + d1;
	int l_y = y - d1;
	while (1)
	{
		map[temp_x][temp_y] = 5;
		if (temp_x == l_x && temp_y == l_y) break;
		++temp_x;
		--temp_y;
	}

	temp_x = x;
	temp_y = y;
	l_x = x + d2;
	l_y = y + d2;
	while (1)
	{
		map[temp_x][temp_y] = 5;
		if (temp_x == l_x && temp_y == l_y) break;
		++temp_x;
		++temp_y;
	}

	temp_x = x + d1;
	temp_y = y - d1;
	l_x = x + d1 + d2;
	l_y = y - d1 + d2;
	while (1)
	{
		map[temp_x][temp_y] = 5;
		if (temp_x == l_x && temp_y == l_y) break;
		++temp_x;
		++temp_y;
	}
	temp_x = x + d2;
	temp_y = y + d2;
	l_x = x + d1 + d2;
	l_y = y - d1 + d2;
	while (1)
	{
		map[temp_x][temp_y] = 5;
		if (temp_x == l_x && temp_y == l_y) break;
		++temp_x;
		--temp_y;
	}
	return true;
}
void map_clear()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) map[i][j] = 0;
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> A[i][j];
		}
	}
}