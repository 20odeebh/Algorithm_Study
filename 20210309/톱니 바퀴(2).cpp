#include<iostream>
#include<vector>
#include<utility>
#define max_n 1000
using namespace std;
vector<pair<int, int>> v;
int cir[max_n + 1][3];
int map[max_n + 1][10];
int n;
int ans;
void print();
void input();
void solution();
void get_info();
void turn(int num, int cl);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	//print();
	solution();
	
	for (int i = 1; i <= n; ++i)
	{
		if (map[i][1] == 1) ++ans;
	}
	cout << ans << '\n';

	return 0;
}
void solution()
{
	int v_size = v.size();
	for (int i = 0; i < v_size; ++i)
	{
		get_info(); // 톱니바퀴 좌우정보 미리 저장 1번 오른 2번 왼정보

		int a, b;
		a = v[i].first;
		b = v[i].second;

		// 오른3번, 왼 7번
		// 같으면 정지, 다르면 반대로 돌리기

		int temp = b;
		turn(a, b);
		for (int i = a + 1; i <= n; ++i) // 현재부터, 오른쪽 정보
		{
			if (cir[i - 1][1] == cir[i][2]) break;
			temp *= -1;
			turn(i, temp);
		}
		temp = b;

		for (int i = a -1; i >= 1; --i) // 현재부터, 왼쪽
		{
			if (cir[i + 1][2] == cir[i][1]) break;
			temp *= -1;
			turn(i, temp);
		}
	}
}
void get_info()
{
	for(int i = 1 ; i <=n ;++i)
	{
		cir[i][1] = map[i][3];
		cir[i][2] = map[i][7];
	}
}
void turn(int num, int cl)
{
	if (cl == 1) // 시계
	{
		int temp[10];
		temp[1] = map[num][8];
		for (int i = 1; i <= 7; ++i)
		{
			temp[i + 1] = map[num][i];
		}
		for (int i = 1; i <= 8; ++i)
		{
			map[num][i] = temp[i];
		}
	}
	else if (cl == -1) // 반시계
	{
		int temp[10];
		
		for (int i = 1; i <= 7; ++i)
		{
			temp[i] = map[num][i+1];
		}
		temp[8] = map[num][1];
		for (int i = 1; i <= 8; ++i)
		{
			map[num][i] = temp[i];
		}
	}
}
void input()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			char ch;
			cin >> ch;
			map[i][j] = ch - '0';
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
}
void print()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}