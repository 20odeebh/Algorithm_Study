#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 20
int ab[MAX_SIZE][MAX_SIZE];
int N, result = 987654321;
int sim(vector<int>& picked)
{
	int team1 = 0, team2 = 0;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (find(picked.begin(), picked.end(), i) == picked.end())
			v.push_back(i);
	}

	int len = N / 2;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i == j)
				continue;
			team1 += ab[picked[i]][picked[j]];
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i == j)
				continue;
			team2 += ab[v[i]][v[j]];
		}
	}
	return abs(team1 - team2);
}
void bf(int n, vector<int>& picked, int toPick, int idx)
{
	if (toPick == 0) {
		result = min(result, sim(picked));
		return;
	}
	int smallest = picked.empty() ? 0 : idx + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		bf(n, picked, toPick - 1, next);
		picked.pop_back();
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &ab[i][j]);
	vector<int> picked;
	bf(N, picked, N / 2, 0);
	printf("%d\n", result);
	return 0;
}