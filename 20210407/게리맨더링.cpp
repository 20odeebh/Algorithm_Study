#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 999999999
#define max_n 10
using namespace std;

int n;
int n_half;
int ans;
vector<int> t1, t2;
int num[max_n + 1];
vector<int> g[max_n + 1];
bool visit[max_n + 1]; // 조합을 위한 용도
bool check[max_n + 1]; // 각 팀 연결확인 용도
void input();
void dfs1(int cur);
void dfs2(int cur);
void comb(int cur, int depth, int end);
void get_ans();
bool is_ok();
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 조합으로 팀나누기 (n/2)
	// 나눈팀이 서로 연결되어있는지, dfs로 확인
	// 가능하다면, 점수차를 비교해 정답구하기
	input();
	ans = INF;
	n_half = n / 2;

	for(int i = 1; i <= n_half; ++i) comb(1, 0, i); // nc1, nc2, nc3.....nc n/2까지

	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
void comb(int cur, int depth, int end)
{
	if (depth == end)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (visit[i]) t1.push_back(i); // true팀
			else t2.push_back(i); // false팀
		}

		if (is_ok()) get_ans(); // 각팀마다 연결되어있는지 확인 후, 최소값 비교

		t1.clear(); // 전역변수이므로 사용하고 clear
		t2.clear();
	
		return;
	}

	for (int i = cur; i <= n; ++i)
	{
		if (!visit[i])
		{
			visit[i] = true;
			comb(i, depth + 1, end);
			visit[i] = false;
		}
	}
}
void print()
{
	int t1_size = t1.size();
	int t2_size = t2.size();

	for (int i = 0; i < t1_size; ++i)
	{
		cout << t1[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < t2_size; ++i)
	{
		cout << t2[i] << ' ';
	}
	cout << '\n';
}
bool is_ok()
{
	bool res = true;

	int t1_size = t1.size();
	int t2_size = t2.size();

	//1팀
	for (int i = 1; i <= n; ++i) check[i] = false;

	check[t1[0]] = true;
	dfs1(t1[0]); // true팀
	for (int i = 0; i < t1_size; ++i)
	{
		if (check[t1[i]] == false)
		{
			res = false;
			break;
		}
	}

	//2팀
	for (int i = 1; i <= n; ++i) check[i] = false;
	check[t2[0]] = true;
	dfs2(t2[0]); // false팀
	for (int i = 0; i < t2_size; ++i)
	{
		if (check[t2[i]] == false)
		{
			res = false;
			break;
		}
	}
	return res;
}
void dfs1(int cur)
{
	int cur_size = g[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		if (!check[g[cur][i]] && visit[g[cur][i]] == true)
		{
			check[g[cur][i]] = true;
			dfs1(g[cur][i]);
		}
	}
}
void dfs2(int cur)
{
	int cur_size = g[cur].size();

	for (int i = 0; i < cur_size; ++i)
	{
		if (!check[g[cur][i]] && visit[g[cur][i]] == false)
		{
			check[g[cur][i]] = true;
			dfs2(g[cur][i]);
		}
	}
}
void get_ans()
{
	int sum1, sum2;
	sum1 = sum2 = 0;
	int t1_size = t1.size();
	int t2_size = t2.size();
	for (int i = 0; i < t1_size; ++i)
	{
		sum1 += num[t1[i]];
	}
	for (int i = 0; i < t2_size; ++i)
	{
		sum2 += num[t2[i]];
	}

	ans = min(ans, abs(sum1 - sum2));
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		int len;
		cin >> len;
		for (int j = 1; j <= len; ++j)
		{
			int node;
			cin >> node;
			g[i].push_back(node);
		}
	}
}