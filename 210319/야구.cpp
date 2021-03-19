#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

const int BASE_MAX = 3;
const int PLAYER_MAX = 9;
const int MAX = 50;

int N;
int temp, result;
int innings[MAX][PLAYER_MAX];
vector<int> v;
deque<int> dq;

void func(int inning)
{
	int out = 0;
	int bases[BASE_MAX] = { 0, };

	for (; out != 3;)
	{
		int cur = dq.front();
		dq.pop_front();
		dq.push_back(cur);

		int player = innings[inning][cur];

		switch (player)
		{
		case 0:
			out++;

			break;
		case 1:
			if (bases[2])
			{
				temp++;

				bases[2] = 0;
			}

			for (int i = 1; i >= 0; i--)
			{
				bases[i + 1] = bases[i];

				bases[i] = 0;
			}

			bases[0] = 1;

			break;
		case 2:
			for (int i = 2; i >= 1; i--)
			{
				if (bases[i])
				{
					temp++;
				}

				bases[i] = 0;
			}

			if (bases[0])
			{
				bases[2] = 1;

				bases[0] = 0;
			}

			bases[1] = 1;

			break;
		default:
			for (int i = 2; i >= 0; i--)
			{
				if (bases[i])
				{
					temp++;
				}

				bases[i] = 0;
			}

			if (player == 3)
			{
				bases[2] = 1;
			}
			else
			{
				temp++;
			}

			break;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < PLAYER_MAX; j++)
		{
			cin >> innings[i][j];
		}
	}

	v.resize(PLAYER_MAX);

	for (int i = 0; i < PLAYER_MAX; i++)
	{
		v[i] = i;
	}

	do
	{
		dq.clear();

		if (v[3] == 0)
		{
			for (int i = 0; i < PLAYER_MAX; i++)
			{
				dq.push_back(v[i]);
			}

			temp = 0;

			for (int i = 0; i < N; i++)
			{
				func(i);
			}

			result = max(result, temp);
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << result << "\n";

	return 0;
}