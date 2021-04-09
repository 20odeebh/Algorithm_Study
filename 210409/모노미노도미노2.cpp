#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

int n;
int dxdy[4][2] = { { 0,0 },{ 0,0 },{ 0,1 },{ 1,0 } };
int score = 0;
int cnt = 0;
vector<vector<int>> board(10, vector<int>(10, 0));

void Delete()
{
	for (int i = 9; i >= 4; i--)
	{
		bool check = true;
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true)
		{
			for (int j = 0; j < 4; j++)
				board[i][j] = 0;
			score++;

			for (int j = 0; j < 4; j++)
			{
				deque<int> temp;
				for (int k = i - 1; k >= 4; k--)
				{
					temp.push_back(board[k][j]);
					board[k][j] = 0;
				}

				int temp_size = temp.size();
				for (int k = i; k > i - temp_size; k--)
				{
					board[k][j] = temp.front();
					temp.pop_front();
				}
			}
			i++;
		}
	}

	int soft_green = 0;
	for (int i = 4; i <= 5; i++)
	{
		bool check = false;
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 0)
			{
				check = true;
				break;
			}
		}

		if (check == true)
			soft_green++;
	}

	for (int j = 0; j < 4; j++)
	{
		deque<int> temp;
		for (int i = 9 - soft_green; i >= 4; i--)
		{
			temp.push_back(board[i][j]);
			board[i][j] = 0;
		}

		int temp_size = temp.size();
		for (int i = 9; i > 9 - temp_size; i--)
		{
			board[i][j] = temp.front();
			temp.pop_front();
		}
	}

	for (int j = 9; j >= 4; j--)
	{
		bool check = true;
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j] == 0)
			{
				check = false;
				break;
			}
		}

		if (check == true)
		{
			for (int i = 0; i < 4; i++)
				board[i][j] = 0;
			score++;

			for (int i = 0; i < 4; i++)
			{
				deque<int> temp;
				for (int k = j - 1; k >= 4; k--)
				{
					temp.push_back(board[i][k]);
					board[i][k] = 0;
				}

				int temp_size = temp.size();
				for (int k = j; k > j - temp_size; k--)
				{
					board[i][k] = temp.front();
					temp.pop_front();
				}
			}
			j++;
		}
	}

	int soft_blue = 0;
	for (int j = 4; j <= 5; j++)
	{
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j] != 0)
			{
				check = true;
				break;
			}
		}

		if (check == true)
			soft_blue++;
	}

	for (int i = 0; i < 4; i++)
	{
		deque<int> temp;
		for (int j = 9 - soft_blue; j >= 4; j--)
		{
			temp.push_back(board[i][j]);
			board[i][j] = 0;
		}

		int temp_size = temp.size();
		for (int j = 9; j > 9 - temp_size; j--)
		{
			board[i][j] = temp.front();
			temp.pop_front();
		}
	}

}

void Move(int t, int x, int y)
{
	pair<int, int> block1 = make_pair(x, y);
	pair<int, int> block2 = make_pair(x + dxdy[t][0], y + dxdy[t][1]);

	while (1)
	{
		if (block1.first + 1 >= 10 || block2.first + 1 >= 10)
		{
			board[block1.first][block1.second] = 1;
			board[block2.first][block2.second] = 1;

			break;
		}

		if (board[block1.first + 1][block1.second] != 0 || board[block2.first + 1][block2.second] != 0)
		{
			board[block1.first][block1.second] = 1;
			board[block2.first][block2.second] = 1;

			break;
		}

		block1.first++;
		block2.first++;
	}

	block1 = make_pair(x, y);
	block2 = make_pair(x + dxdy[t][0], y + dxdy[t][1]);
	while (1)
	{
		if (block1.second + 1 >= 10 || block2.second + 1 >= 10)
		{
			board[block1.first][block1.second] = 1;
			board[block2.first][block2.second] = 1;

			break;
		}

		if (board[block1.first][block1.second + 1] != 0 || board[block2.first][block2.second + 1] != 0)
		{
			board[block1.first][block1.second] = 1;
			board[block2.first][block2.second] = 1;

			break;
		}

		block1.second++;
		block2.second++;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t, x, y;

		cin >> t >> x >> y;

		Move(t, x, y);
		Delete();
	}

	for (int i = 4; i < 10; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] != 0)
				cnt++;

	for (int j = 4; j < 10; j++)
		for (int i = 0; i < 4; i++)
			if (board[i][j] != 0)
				cnt++;

	cout << score << "\n";
	cout << cnt;

	return 0;
}