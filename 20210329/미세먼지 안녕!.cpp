#include<iostream>
#include<vector>
#include<utility>
#define max_n 50
using namespace std;

int n, m, t;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int map[max_n + 1][max_n + 1];
vector<pair<int, int>> aircon;
int ans;

void input();
void move_func();
void print();
void solution();
void air_func();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 1. ���� �����̴� �Լ� ����
	// 2. ����û���� �Լ� ����
	// 3. t�ʰ� ������, ���� ���� �������� üũ
	input();
	solution();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	for (int i = 1; i <= t; ++i)
	{
		move_func();
		air_func();
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (map[i][j] == -1) continue;
			ans += map[i][j];
		}
	}
}
void air_func()
{
	int f_x = aircon[0].first; // ��
	int f_y = aircon[0].second; // 
	int s_x = aircon[1].first; // �Ʒ�
	int s_y = aircon[1].second;
	
	int temp_map[max_n + 1][max_n + 1] = { 0, };

	temp_map[f_x][f_y] = temp_map[s_x][s_y] = -1;

	// �ݽð�
	for (int i = f_y + 2; i <= m; ++i) // ��->����
	{
		temp_map[f_x][i] = map[f_x][i - 1];
	}
	for (int i = f_x - 1; i >= 1; --i) // �Ʒ� -> ��
	{
		temp_map[i][m] = map[i + 1][m];
	}
	for (int i = m - 1; i >= 1; --i) // ���� -> ��
	{
		temp_map[1][i] = map[1][i + 1];
	}
	for (int i = 2; i < f_x; ++i) // �� -> �Ʒ�
	{
		temp_map[i][1] = map[i - 1][1];
	}
	//�ð�

	for (int i = s_y + 2; i <= m; ++i) // �� -> ����
	{
		temp_map[s_x][i] = map[s_x][i - 1];
	}
	for (int i = s_x + 1; i <= n; ++i) // ��->�Ʒ�
	{
		temp_map[i][m] = map[i - 1][m]; 
	}
	for (int i = m - 1; i >= 1; --i) // ���� -> ��
	{
		temp_map[n][i] = map[n][i + 1];
	}
	for (int i = n - 1; i > s_x; --i) // �Ʒ� -> ��
	{
		temp_map[i][1] = map[i + 1][1];
	}

	// �ű��

	for (int i = 2; i <= m; ++i)
	{
		map[f_x][i] = temp_map[f_x][i];
	}
	for (int i = f_x; i >= 1; --i)
	{
		map[i][m] = temp_map[i][m];
	}
	for (int i = m; i >= 1; --i)
	{
		map[1][i] = temp_map[1][i];
	}
	for (int i = 1; i < f_x; ++i)
	{
		map[i][1] = temp_map[i][1];
	}

	//

	for (int i = 1; i <= m; ++i)
	{
		map[s_x][i] = temp_map[s_x][i];
	}
	for (int i = s_x; i <= n; ++i)
	{
		map[i][m] = temp_map[i][m];
	}
	for (int i = m; i >= 1; --i)
	{
		map[n][i] = temp_map[n][i];
	}
	for (int i = n; i > s_x; --i)
	{
		map[i][1] = temp_map[i][1];
	}
}
void move_func()
{
	int temp_map[max_n + 1][max_n + 1] = { 0, }; // ������¸��� ����
	
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			int cur_sum = map[i][j];
			if (cur_sum == 0) continue; // ���� ������ ����
			
			int cur_cnt = 0; // Ȯ�� ���� ����
			int temp = (cur_sum / 5); // Ȯ�� ��

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
				if (map[nx][ny] == -1) continue;

				++cur_cnt;
				temp_map[nx][ny] += temp;
			}
			temp_map[i][j] += map[i][j] - (temp * cur_cnt);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			map[i][j] = temp_map[i][j];
		}
	}
}
void input()
{
	cin >> n >> m >> t;
	for(int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1) aircon.push_back({ i,j });
		}
	}
}
void print()
{
	cout << "\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}