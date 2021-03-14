#include<iostream>
#include<string>
using namespace std;

int s;
string n;
void input(); // s+2 ����, 2s+3 ����
void solution();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	solution();


	return 0;
}
void solution()
{
	int h_len = 2 * s + 3;
	int n_len = n.length();
	for (int h = 0; h < h_len; ++h)
	{
		for (int i = 0; i < n_len; ++i)
		{
			if (h == 0) // ����
			{
				if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9')
				{
					cout << " ";
					for (int j = 0; j < s; ++j)
					{
						cout << "-";
					}
					cout << " ";
				}
				else // 1,4
				{
					for (int j = 0; j < s + 2; ++j)
					{
						cout << " ";
					}
				}
			}
			else if (h >= 1 && h <= s) // �߻�
			{
				if (n[i] == '0' || n[i] == '4' || n[i] == '8' || n[i] == '9')
				{
					cout << "|";
					for (int j = 0; j < s; ++j)
					{
						cout << " ";
					}
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7')
				{
					for (int j = 0; j < s + 1; ++j)
					{
						cout << " ";
					}
					cout << "|";
				}
				else // 5,6
				{
					cout << "|";
					for (int j = 0; j < s + 1; ++j)
					{
						cout << " ";
					}
				}
			}
			else if (h == s + 1) // �߰�
			{
				if (n[i] == '0' || n[i] == '1' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; ++j)
					{
						cout << " ";
					}
				}
				else // �׿�
				{
					cout << " ";
					for (int j = 0; j < s; ++j)
					{
						cout << "-";
					}
					cout << " ";
				}
				
			}
			else if (s + 2 <= h && h <= 2 * s + 1) // ����
			{
				if (n[i] == '0' || n[i] == '6' || n[i] == '8')
				{
					cout << "|";
					for (int j = 0; j < s; ++j)
					{
						cout << " ";
					}
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '7' || n[i] == '9')
				{
					for (int j = 0; j < s + 1; ++j)
					{
						cout << " ";
					}
					cout << "|";
				}
				else
				{
					cout << "|";
					for (int j = 0; j < s + 1; ++j)
					{
						cout << " ";
					}
				}
			}
			else // �� ��
			{
				if (n[i] == '1' || n[i] == '4' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; ++j)
					{
						cout << " ";
					}
				}
				else
				{
					cout << " ";
					for (int j = 0; j < s; ++j)
					{
						cout << "-";
					}
					cout << " ";
				}
			}
			cout << " ";
		}
		cout << '\n';
	}
}
void input()
{
	cin >> s >> n;
}