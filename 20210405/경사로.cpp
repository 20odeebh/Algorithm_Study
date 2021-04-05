#include<iostream>
#include<vector>
#define max_n 100
using namespace std;

int n, L;
int map[max_n + 1][max_n + 1];
int ans;
vector<int> v;
void input();
void solution();
bool check();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();
	
	cout << ans << '\n';

	return 0;
}
void solution()
{
	for (int i = 1; i <= n; ++i) // ����
	{
		v.clear();
		for (int j = 1; j <= n; ++j)
		{
			v.push_back(map[i][j]);
		}
		if(check()) ++ans;
	}

	for (int i = 1; i <= n; ++i) // ����
	{
		v.clear();
		for (int j = 1; j <= n; ++j)
		{
			v.push_back(map[j][i]);
		}
		if (check()) ++ans;
	}
}
bool check()
{
	bool res = true;
	int v_size = v.size();

	// ���δ� ����ĭ��
	// L���� ���ӵǰ�
	// ��,�� ���� 2�̻� x
	
	int cnt = 1; // ���� ���� �ݺ�����

	for (int i = 0; i < v_size - 1; ++i)
	{
		if (v[i] == v[i + 1]) ++cnt;
		else if (v[i] > v[i + 1]) // ���� �κ��� ���� ���
		{
			if (v[i] - v[i + 1] > 1)  // 2�̻� ����
			{
				res = false; 
				break;
			}
			if (i + L > n - 1) // �ݺ����� üũ�� ������ ���°��
			{
				res = false;
				break;
			}

			bool temp = true;
			for (int k = i + 1; k < i + L; ++k) // üũ�� ������ �ִ°��, L����ŭ �������� üũ
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
			else // L����ŭ �����ϴٸ�, ���γ��� ����
			{
				i = i + L - 1;
				cnt = 0;
			}
		}
		else // ���� �κ��� ���� ���
		{
			if (v[i + 1] - v[i] > 1) // 2�̻��� ��������
			{
				res = false;
				break;
			}
			if (cnt >= L) cnt = 1; // ���� ���� �ݺ��� L�̻��̸� ���� ��ġ ����
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