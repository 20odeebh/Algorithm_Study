#include<iostream>
#include<vector>
#define max_n 100
using namespace std;

int map[max_n + 1][max_n + 1];
int N, L;
void input();
int ans;
vector<int> v;
void solution();
bool check();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	for (int i = 1; i <= N; ++i)
	{
		v.clear();
		for (int j = 1; j <= N; ++j)
		{
			v.push_back(map[i][j]);
		}
		solution();
	}
	for (int i = 1; i <= N; ++i)
	{
		v.clear();
		for (int j = 1; j <= N; ++j)
		{
			v.push_back(map[j][i]);
		}
		solution();
	}

	cout << ans << '\n';

	return 0;
}
void solution()
{
	if (check()) { ++ans; return; }
}
bool check()
{
	int v_size = v.size();
	bool res = true;

	int cnt = 1;

	for (int i = 0; i < v_size - 1; ++i)
	{
		if (v[i] == v[i + 1]) ++cnt;
		else if (v[i] > v[i + 1]) // 앞이 클 때
		{
			if (v[i] - v[i + 1] > 1) { res = false; break; }//2이상 차이
			//todo
			if (i + L > N - 1) { res = false; break; }

			bool is_ok = true;

			for (int k = i + 1; k < i + L; ++k)
			{
				if (v[k] != v[k + 1]) { is_ok = false; break; }
			}
			if (!is_ok) { res = false; break; }
			else
			{
				i = i + L - 1;
				cnt = 0;
			}
		}
		else
		{
			if (v[i + 1] - v[i] > 1) { res = false; break; }
			//todo
			if (cnt >= L) { cnt = 1; }
			else { res = false; break; }
		}
	}
	return res;
}
void input()
{
	cin >> N >> L;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
		}
	}
}