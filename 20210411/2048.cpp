#include<iostream>
#include<vector>
#define max_n 20
using namespace std;
int map[max_n + 2][max_n + 2];
int temp_map[max_n + 2][max_n + 2];
int use[max_n + 2][max_n + 2];
int N;
int num[5];
int ans;
vector<int> ary;

void solution();
void init();
void Print();
void temp_to_map();
void map_to_temp();
void down_func();
void up_func();
void left_func();
void right_func();
void up_check();
void down_check();
void left_check();
void right_check();
void use_clear();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	up_func();
	//down_func();
	//right_func();
	//left_func();
	init();
	for (int i = 1; i <= 4; ++i)
	{
		for (int ii = 1; ii <= 4; ++ii)
		{
			for (int iii = 1; iii <= 4; ++iii)
			{
				for (int iiii = 1; iiii <= 4; ++iiii)
				{
					for (int iiiii = 1; iiiii <= 4; ++iiiii)
					{
						map_to_temp();
						ary.push_back(i);
						ary.push_back(ii);
						ary.push_back(iii);
						ary.push_back(iiii);
						ary.push_back(iiiii);
						solution();
						ary.clear();
						temp_to_map();
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
void solution()
{
	int ary_size = ary.size();
	/*ary[0] = 1;
	ary[1] = 3;
	ary[2] = 4;
	ary[3] = 1;
	ary[4] = 3;*/
	for (int i = 0; i < ary_size; ++i)
	{
		switch (ary[i]) {
		case 1: up_func(); up_check(); up_func(); break;
		case 2: down_func(); down_check(); down_func(); break;
		case 3: left_func(); left_check(); left_func(); break;
		case 4: right_func(); right_check(); right_func(); break;
		}
		//Print();
	}
	// 1 : 위
	// 2 : 아래
	// 3 : 왼쪽
	// 4 : 오른쪽
	int max = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			max = map[i][j] > max ? map[i][j] : max;
		}
	}
	/*if (max == 32)
	{
		for (int i = 0; i < 5; ++i)
		{
			cout << ary[i];
		}
		cout << '\n';
	}*/
	ans = ans > max ? ans : max;
}
void left_check()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] = map[i][j] * 2;
				map[i][j + 1] = 0;
			}
		}
	}
}
void right_check()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = N; j >= 1; --j)
		{
			if (map[i][j] == map[i][j - 1])
			{
				map[i][j] = map[i][j] * 2;
				map[i][j - 1] = 0;
			}
		}
	}
}
void up_check()
{
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (map[i][j] == map[i + 1][j])
			{
				map[i][j] = map[i][j] * 2;
				map[i + 1][j] = 0;
			}
		}
	}
}
void down_check()
{
	for (int j = 1; j <= N; ++j)
	{
		for (int i = N; i >= 1; --i)
		{
			if (map[i][j] == map[i - 1][j])
			{
				map[i][j] = map[i][j] * 2;
				map[i - 1][j] = 0;
			}
		}
	}
}
void up_func()
{
	use_clear();

	int x = 1;
	int y = 1;

	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			int temp;
			temp = map[i][j];

			if (temp != 0)
			{
				use[x][y] = temp;
				++x;
			}
		}
		x = 1;
		++y;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = use[i][j];
		}
	}
}
void down_func()
{
	use_clear();
	int x = N;
	int y = 1;
	for (int j = 1; j <= N; ++j)
	{
		for (int i = N; i >= 1; --i)
		{
			int temp;
			temp = map[i][j];

			if (temp != 0)
			{
				use[x][y] = map[i][j];
				--x;
			}
		}
		x = N;
		++y;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = use[i][j];
		}
	}
}
void left_func()
{
	use_clear();
	int x = 1;
	int y = 1;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int temp;
			temp = map[i][j];

			if (temp != 0)
			{
				use[x][y] = map[i][j];
				++y;
			}
		}
		y = 1;
		++x;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = use[i][j];
		}
	}
}
void right_func()
{
	use_clear();
	int x = 1;
	int y = N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = N; j >= 1; --j)
		{
			int temp;
			temp = map[i][j];

			if (temp != 0)
			{
				if (temp != 0)
				{
					use[x][y] = map[i][j];
					--y;
				}
			}
		}
		y = N;
		++x;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = use[i][j];
		}
	}
}
void temp_to_map()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = temp_map[i][j];
		}
	}
}
void map_to_temp()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			temp_map[i][j] = map[i][j];
		}
	}
}
void use_clear()
{
	for (int i = 0; i <= N + 1; ++i)
	{
		for (int j = 0; j <= N + 1; ++j)
		{
			use[i][j] = 0;
		}
	}
}
void Print()
{
	cout << "\n\n";
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	getchar();
}
void init()
{
	for (int i = 0; i <= N + 1; ++i)
	{
		for (int j = 0; j <= N + 1; ++j)
		{
			map[i][j] = 0;
		}
	}
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= 4; ++i)
	{
		num[i] = i;
	}
}