#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 15;

int N, M, D;
int arr[MAX][MAX];
int copyArr[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> D;

	vector<pair<int, int>> enemy;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				// ������ ��ǥ�� ��� �־��ش�
				enemy.push_back({ i, j });
			}
		}
	}

	/*
	next_permutation�� �̿��� ���̱� ������
	00..0111 ���� ����
	*/
	vector<int> archer;
	for (int i = 0; i < M - 3; i++)
	{
		archer.push_back(0);
	}

	for (int i = 0; i < 3; i++)
	{
		archer.push_back(1);
	}

	int result = 0;
	do
	{
		int cnt = 0;
		// ������ ��ǥ�� ����
		vector<pair<int, int>> temp = enemy;

		vector<int> v;
		for (int i = 0; i < archer.size(); i++)
		{
			if (archer[i] == 1)
			{
				// ���� �ü� ��ġ ����
				v.push_back(i);
			}
		}

		while (!temp.empty())
		{
			int y = N;
			vector<int> target;

			// �ü��� ���ÿ� ����
			for (int i = 0; i < v.size(); i++)
			{
				int x = v[i];
				int idx = 0;
				int enemyX = temp[0].second;
				int dist = abs(y - temp[0].first) + abs(x - temp[0].second);
				for (int j = 1; j < temp.size(); j++)
				{
					int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second);

					// �� ����� ��
					if (dist > tempDist)
					{
						enemyX = temp[j].second;
						dist = tempDist;
						idx = j;
					}
					// �Ÿ��� ���ٸ� �� ���ʿ� �ִ� ��
					else if (dist == tempDist && enemyX > temp[j].second)
					{
						enemyX = temp[j].second;
						idx = j;
					}
				}

				// D �̳��� �ִ� ���� óġ ����
				if (dist <= D)
				{
					target.push_back(idx);
				}
			}

			// ���ÿ� �����ϱ� ������ �ߺ��� �� ���� �� �ִ�
			target.erase(unique(target.begin(), target.end()), target.end());
			sort(target.begin(), target.end());
			int shoot = 0;
			// ���� óġ
			for (int i = 0; i < target.size(); i++)
			{
				temp.erase(temp.begin() + (target[i] - shoot++));
				cnt++;
			}

			if (temp.empty())
			{
				break;
			}

			// ��ĭ �Ʒ���
			vector<pair<int, int>> copyTemp;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].first < N - 1)
				{
					copyTemp.push_back({ temp[i].first + 1, temp[i].second });
				}
			}

			temp = copyTemp;
		}

		result = max(result, cnt);
	} while (next_permutation(archer.begin(), archer.end()));

	cout << result << "\n";
	return 0;
}