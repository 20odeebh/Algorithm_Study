#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

vector<pair<int, int>> order;
int ans;
int map[5][10]; // 12�ú��� �ð�������� 1~8����
int check[5];
void input();
void solution();
void get_ans();
void turn_func();
void print();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	get_ans();

	cout << ans << '\n';

	return 0;
}
void solution()
{
	//�� ��ġ����, �������� 3��, ������ 7��
	// ����ġ 3��, ������ġ 7����
	// ����ġ 7��, ������ġ 3�� ��
	int order_size = order.size();
	for (int i = 0; i < order_size; ++i)
	{
		int num, turn;
		num = order[i].first;
		turn = order[i].second;

		for (int i = 1; i <= 4; ++i) check[i] = 0; // check�Լ���, �� ��Ϲ����� ���ԵǸ�, -1 or 1�� �ʱ�ȭ

		check[num] = turn; 

		int temp_turn = turn;
		
		for (int k = num + 1; k <= 4; ++k) // ������
		{
			if (map[k - 1][3] == map[k][7]) break; // ���� ���̸�
			temp_turn *= -1; // �ݴ�� ����
			check[k] = temp_turn;
		}

		temp_turn = turn;
		for (int k = num - 1; k >= 1; --k) // ����
		{
			if (map[k + 1][7] == map[k][3]) break;
			temp_turn *= -1;
			check[k] = temp_turn;
		}

		turn_func(); // check�� ������� ���ԵǴ� ��Ϲ��� ����
	}
}
void turn_func()
{
	for (int i = 1; i <= 4; ++i)
	{
		int temp_map[10] = {0,};

		if (check[i] == 0) continue;
		else if (check[i] == 1) // �ð�
		{
			for (int k = 2; k <= 8; ++k)
			{
				temp_map[k] = map[i][k-1];
			}
			temp_map[1] = map[i][8];
		}
		else if(check[i] == -1) // �ݽð�
		{
			for(int k = 2; k <= 8; ++k)
			{
				temp_map[k - 1] = map[i][k];
			}
			temp_map[8] = map[i][1];
		}
		for (int k = 1; k <= 8; ++k) map[i][k] = temp_map[k];
	}
}
void get_ans()
{
	for (int i = 1; i <= 4; ++i)
	{
		if (map[i][1] == 0) continue;
		else
		{
			ans += (int)pow(2, i - 1);
		}
	}
}
void input()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			char ch;
			cin >> ch;
			map[i][j] = int(ch - '0');
		}
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int a, b;
		cin >> a >> b;
		order.push_back({ a,b });
	}
}
void print()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 8; ++j)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}