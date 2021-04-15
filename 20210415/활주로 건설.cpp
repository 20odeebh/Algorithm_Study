#include<iostream>
#include<vector>
#define max_n 100
using namespace std;

int n, L;
int map[max_n + 1][max_n + 1];
vector<int> ans;
vector<int> v;
void input();
void solution();
bool check();
void clear_func();

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

		clear_func();
	}
	
	int ans_size = ans.size();

	for (int i = 0; i < ans_size; ++i)
	{
		cout << '#' << i + 1 << ' ' << ans[i] << '\n';

	}

	return 0;
}
void clear_func()
{
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			map[i][j] = 0;
		}
	}
	v.clear();
}
void solution()
{
	int sum = 0;

	for (int i = 1; i <= n; ++i) // 가로
	{
		v.clear();
		for (int j = 1; j <= n; ++j)
		{
			v.push_back(map[i][j]);
		}
		if (check()) ++sum;
	}

	for (int i = 1; i <= n; ++i) // 세로
	{
		v.clear();
		for (int j = 1; j <= n; ++j)
		{
			v.push_back(map[j][i]);
		}
		if (check()) ++sum;
	}

	ans.push_back(sum);
}
bool check()
{
	bool res = true;
	int v_size = v.size();

	// 경사로는 낮은칸에
	// L개로 연속되게
	// 낮,높 차이 2이상 x

	int cnt = 1; // 같은 경사로 반복갯수

	for (int i = 0; i < v_size - 1; ++i)
	{
		if (v[i] == v[i + 1]) ++cnt;
		else if (v[i] > v[i + 1]) // 낮은 부분이 나온 경우
		{
			if (v[i] - v[i + 1] > 1)  // 2이상 차이
			{
				res = false;
				break;
			}
			if (i + L > n - 1) // 반복경사로 체크할 범위가 없는경우
			{
				res = false;
				break;
			}

			bool temp = true;
			for (int k = i + 1; k < i + L; ++k) // 체크할 범위가 있는경우, L개만큼 평평한지 체크
			{
				if (v[k] != v[k + 1])
				{
					temp = false;
					break;
				}
			}
			if (!temp)
			{
				res = false;
				break;
			}
			else // L개만큼 평평하다면, 경사로놓고 점프
			{
				i = i + L - 1;
				cnt = 0;
			}
		}
		else // 높은 부분이 나온 경우
		{
			if (v[i + 1] - v[i] > 1) // 2이상의 높이차이
			{
				res = false;
				break;
			}
			if (cnt >= L) cnt = 1; // 같은 경사로 반복이 L이상이면 경사로 설치 가능
			else
			{
				res = false;
				break;
			}
		}

	}


	return res;
}
void input()
{
	cin >> n >> L;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> map[i][j];
		}
	}
}