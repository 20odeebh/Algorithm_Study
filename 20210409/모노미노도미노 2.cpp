#include<iostream>
#include<vector>
#define max_n 4
using namespace std;

typedef struct 
{
	int t, x, y; // t:1칸, t2 가로(y+1), t3 : 세로(x+1)
}block;

int red[max_n + 1][max_n + 1];
int blue[max_n + 3][max_n + 1];
int green[max_n + 3][max_n + 1];
int score;
int block_cnt;
vector<block> v;

void print();
void input();
void solution();
void add_green(int t, int x, int y);
void add_blue(int t, int x, int y);
void check_func();
void special_func();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();

	cout << score << '\n' << block_cnt << '\n';


	//1. 블럭 놓기
	//2. 4개 쌓인 블럭체크 -> 그 위의 행들 없어진만큼 밑으로
	//3. 특별공간 확인
	return 0;
}
void solution()
{
	int v_size = v.size();

	for (int t = 0; t < v_size; ++t)
	{
		int cur_t, cur_x, cur_y;
		cur_t = v[t].t;
		cur_x = v[t].x;
		cur_y = v[t].y;

		add_green(cur_t, cur_x, cur_y);
		add_blue(cur_t, cur_x, cur_y);

		check_func();
		special_func();
		//print();
	}

	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (green[i][j] == 1)++block_cnt;
			if (blue[i][j] == 1) ++block_cnt;
		}
	}

}
void special_func()
{
	int temp[max_n + 3][max_n + 1] = { 0, };

	int g_cnt = 0;
	int b_cnt = 0;

	for (int i = 1; i <= 2; ++i)
	{
		bool g_check = false;
		bool b_check = false;

		for (int j = 1; j <= 4; ++j)
		{
			if (green[i][j] == 1) g_check = true;
			if (blue[i][j] == 1) b_check = true;
		}
		if (g_check) ++g_cnt;
		if (b_check) ++b_cnt;
	}

	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			temp[i][j] = 0;
		}
	}

	for (int i = 6 - g_cnt; i >= 1; --i) // 특별공간 있는 행의 수만큼 맨아래 제외
	{
		for (int j = 1; j <= 4; ++j)
		{
			temp[i+g_cnt][j] = green[i][j]; 
		}
	}

	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			green[i][j] = temp[i][j];
			temp[i][j] = 0; // blue 사용하기위해 0으로
		}
	}


	for (int i = 6 - b_cnt; i >= 1; --i) // 특별공간 있는 행의 수만큼 맨아래 제외
	{
		for (int j = 1; j <= 4; ++j)
		{
			temp[i+b_cnt][j] = blue[i][j];
		}
	}

	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			blue[i][j] = temp[i][j];
		}
	}
}
void check_func()
{
	int temp[max_n + 3][max_n + 1] = {0,};
	while (1)
	{
		bool is_moved = false;
		for (int i = 6; i >= 1; --i)
		{
			int cnt = 0;
			for (int j = 1; j <= 4; ++j)
			{
				if (green[i][j] == 1) ++cnt;
			}
			if (cnt == 4)
			{
				++score;
				is_moved = true;
				if (i == 1) break; // 맨위에꺼 없어진경우 옮길필요 x

				for (int k = i - 1; k >= 1; --k) // 
				{
					for (int j = 1; j <= 4; ++j)
					{
						temp[k + 1][j] = green[k][j];
					}
				}

				for (int k = i; k >= 1; --k) // 옮기기
				{
					for (int j = 1; j <= 4; ++j)
					{
						green[k][j] = temp[k][j];
					}
				}
				for (int j = 1; j <= 4; ++j) // 맨위에거 비워주기 
				{
					green[1][j] = 0;
				}
			}
		}
		if (is_moved == false) break;
	}

	while (1)
	{
		bool is_moved = false;
		for (int i = 6; i >= 1; --i)
		{
			int cnt = 0;
			for (int j = 1; j <= 4; ++j)
			{
				if (blue[i][j] == 1) ++cnt;
			}
			if (cnt == 4)
			{
				is_moved = true;
				++score;
				if (i == 1) break; // 맨위에꺼 없어진경우 옮길필요 x

				for (int k = i - 1; k >= 1; --k) // 
				{
					for (int j = 1; j <= 4; ++j)
					{
						temp[k + 1][j] = blue[k][j];
					}
				}

				for (int k = i; k >= 1; --k) // 옮기기
				{
					for (int j = 1; j <= 4; ++j)
					{
						blue[k][j] = temp[k][j];
					}
				}
				for (int j = 1; j <= 4; ++j) // 맨위에거 비워주기 
				{
					blue[1][j] = 0;
				}
			}
		}
		if (is_moved == false) break;
	}
}
void add_blue(int t, int x, int y)
{
	if (x == 1) y = 4;
	else if (x == 2) y = 3;
	else if (x == 3) y = 2;
	else if (x == 4) y = 1;

	if (t == 2) t = 3;
	else if (t == 3) t = 2;

	bool temp = true;

	for (int i = 1; i <= 6; ++i)
	{
		if (t == 1)
		{
			if (blue[i][y] != 0) temp = false;
		}
		else if (t == 2)
		{
			if (blue[i][y] != 0 || blue[i][y - 1] != 0) temp = false;
		}
		else if (t == 3)
		{
			if (blue[i][y] != 0 || blue[i - 1][y] != 0) temp = false;
		}
		if (!temp) // 내려갈수없으면, 그전자리
		{
			if (t == 1) blue[i-1][y] = 1;
			else if (t == 2)
			{
				blue[i-1][y] = 1;
				blue[i-1][y - 1] = 1;
			}
			else if (t == 3)
			{
				blue[i-1][y] = 1;
				blue[i - 2][y] = 1;
			}
			break;
		}
		if (i == 6)
		{
			if (t == 1) blue[i][y] = 1;
			else if (t == 2)
			{
				blue[i][y] = 1;
				blue[i][y - 1] = 1;
			}
			else if (t == 3)
			{
				blue[i][y] = 1;
				blue[i - 1][y] = 1;
			}
			break;
		}
	}
}
void add_green(int t, int x, int y)
{
	bool temp = true;

	for (int i = 1; i <= 6; ++i)
	{
		if (t == 1)
		{
			if (green[i][y] != 0) temp = false;
		}
		else if (t == 2)
		{
			if (green[i][y] != 0 || green[i][y + 1] != 0) temp = false;
		}
		else if (t == 3)
		{
			if (green[i][y] != 0 || green[i - 1][y] != 0) temp = false;
		}
		if (!temp) // 내려갈수없으면, 그전자리
		{
			if (t == 1) green[i - 1][y] = 1;
			else if (t == 2)
			{
				green[i - 1][y] = 1;
				green[i - 1][y + 1] = 1;
			}
			else if (t == 3)
			{
				green[i - 1][y] = 1;
				green[i - 2][y] = 1;
			}
			break;
		}
		if (i == 6)
		{
			if (t == 1) green[i][y] = 1;
			else if (t == 2)
			{
				green[i][y] = 1;
				green[i][y + 1] = 1;
			}
			else if (t == 3)
			{
				green[i][y] = 1;
				green[i - 1][y] = 1;
			}
			break;
		}
		
	}
}
void print()
{
	cout << "green\n";
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			cout << green[i][j];
		}
		cout << '\n';
	}

	cout << "\nblue\n";
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			cout << blue[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

}
void input()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int t, x, y;
		cin >> t >> x >> y;
		v.push_back({ t,x + 1,y + 1 });
	}
}