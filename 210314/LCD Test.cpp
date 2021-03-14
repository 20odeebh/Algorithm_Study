#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int s;
	string n;
	cin >> s >> n;

	for (int h = 0; h < 2 * s + 3; h++)
	{
		for (int i = 0; i < n.length(); i++)
		{
			//제일 위 줄
			if (h == 0)
			{
				if (n[i] == '0' || n[i] == '2' || n[i] == '3' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9')
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
				else
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
			}
			//몸통 위쪽
			else if (1 <= h && h <= s)
			{
				if (n[i] == '0' || n[i] == '4' || n[i] == '8' || n[i] == '9')
				{
					cout << "|";
					for (int j = 0; j < s; j++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '7')
				{
					for (int j = 0; j < s + 1; j++)
						cout << " ";
					cout << "|";
				}
				else
				{
					cout << "|";
					for (int j = 0; j < s + 1; j++)
						cout << " ";
				}
			}
			//가운데
			else if (h == s + 1)
			{
				if (n[i] == '0' || n[i] == '1' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
				else
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
			}
			//몸통 아래쪽
			else if (s + 2 <= h && h <= 2 * s + 1)
			{
				if (n[i] == '0' || n[i] == '6' || n[i] == '8')
				{
					cout << "|";
					for (int j = 0; j < s; j++)
						cout << " ";
					cout << "|";
				}
				else if (n[i] == '1' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '7' || n[i] == '9')
				{
					for (int j = 0; j < s + 1; j++)
						cout << " ";
					cout << "|";
				}
				else
				{
					cout << "|";
					for (int j = 0; j < s + 1; j++)
						cout << " ";
				}
			}
			//맨 아랫줄
			else
			{
				if (n[i] == '1' || n[i] == '4' || n[i] == '7')
				{
					for (int j = 0; j < s + 2; j++)
						cout << " ";
				}
				else
				{
					cout << " ";
					for (int j = 0; j < s; j++)
						cout << "-";
					cout << " ";
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
	return 0;
}