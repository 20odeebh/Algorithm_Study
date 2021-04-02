#include<iostream>
#include<vector>
#include<algorithm>

#define max_n 100
using namespace std;

int r, c, k;
int ans;
int m_row, m_col;
int map[max_n + 1][max_n + 1];
int num_cnt[max_n + 1];
void input();
void solution();
void find_max();
void R_func();
void C_func();
void cnt_clear();
void print();
bool cmp(int a, int b)
{
	return a > b;
}
bool cmp2(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	else
	{
		return a.second < b.second;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//1. row, col 가장 큰 길이 구하기
	//2. R연산 C연산
	//3. r,c가 k인지 확인
	//4. ans가 100이상이면 -1출력
	input();

	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	while (1)
	{
		if (map[r][c] == k) break;
		if(ans > 100)
		{
			ans = -1;
			break;
		}
		find_max(); 

		if (m_row >= m_col) R_func();
		else C_func();

		//print();
		
		++ans;
	}
}
void R_func()
{
	vector<int> v;
	for (int i = 1; i <= m_row; ++i)
	{
		v.clear();
		cnt_clear();
		for (int j = 1; j <= m_col; ++j)
		{
			if (map[i][j] == 0) continue;
			v.push_back(map[i][j]);
			++num_cnt[map[i][j]]; // 빈도수 저장
		}
		sort(v.begin(), v.end(), cmp); // 역순정렬
		v.erase(unique(v.begin(), v.end()), v.end()); // 중복제거

		vector<pair<int, int>> temp;

		int v_size = v.size();
		for (int k = 0; k < v_size; ++k)
		{
			int cur_num = v[k]; // 저장할 수
			int cur_len = num_cnt[cur_num]; // 저장할 수의 빈도
			temp.push_back({ cur_num, cur_len });
		}

		sort(temp.begin(), temp.end(), cmp2);
		int temp_size = temp.size();
		
		for (int k = 1; k <= 100; ++k) map[i][k] = 0; // 맵에 저장하기 전에, 기존거 0으로 초기화

		for(int k = 0; k < temp_size; ++k) // k가 0일때, 1,2번방 저장 / k가 1일때 3,4번방 저장 방식
		{
			map[i][2 * k + 1] = temp[k].first;
			map[i][2 * k + 2] = temp[k].second;
		}

		temp.clear();
	}
}
void C_func()
{
	vector<int> v;
	for (int i = 1; i <= m_col; ++i)
	{
		v.clear();
		cnt_clear();
		for (int j = 1; j <= m_row; ++j)
		{
			if (map[j][i] == 0) continue;
			v.push_back(map[j][i]);
			++num_cnt[map[j][i]]; // 빈도수 저장
		}
		sort(v.begin(), v.end(), cmp); // 역순정렬
		v.erase(unique(v.begin(), v.end()), v.end()); // 중복제거

		vector<pair<int, int>> temp;

		int v_size = v.size();
		for (int k = 0; k < v_size; ++k)
		{
			int cur_num = v[k]; // 저장할 수
			int cur_len = num_cnt[cur_num]; // 저장할 수의 빈도
			temp.push_back({ cur_num, cur_len });
		}

		sort(temp.begin(), temp.end(), cmp2);
		int temp_size = temp.size();

		for (int k = 1; k <= 100; ++k) map[k][i] = 0; // 맵에 저장하기 전에, 기존거 0으로 초기화

		for (int k = 0; k < temp_size; ++k) // k가 0일때, 1,2번방 저장 / k가 1일때 3,4번방 저장 방식
		{
			map[2 * k + 1][i] = temp[k].first;
			map[2 * k + 2][i] = temp[k].second;
		}

		temp.clear();
	}
}
void print()
{
	for (int i = 1; i <= 10; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void cnt_clear()
{
	for (int i = 1; i <= max_n; ++i) num_cnt[i] = 0;
}
void find_max()
{
	m_row = m_col = 0;
	for (int i = 1; i <= 100; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= 100; ++j)
		{
			if (map[i][j] == 0) break;
			++sum;
		}
		m_col = max(sum, m_col);
	}

	for (int i = 1; i <= 100; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= 100; ++j)
		{
			if (map[j][i] == 0) break;
			++sum;
		}
		m_row = max(sum, m_row);
	}
}
void input()
{
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			cin >> map[i][j];
		}
	}
}