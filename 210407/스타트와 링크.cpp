// 스타트와 링크

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

int n, res = INT_MAX;
int arr[21][21], P[20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	for (int i = n / 2; i < n; i++) P[i] = 1;
	do {
		std::vector<int> team_a, team_b;
		for (int i = 0; i < n; i++) {
			if (P[i]) team_a.push_back(i);
			else team_b.push_back(i);
		}
		int A = 0;
		for (int j = 0; j < team_a.size(); j++)
			for (int k = 0; k < team_a.size(); k++)
				A += arr[team_a[j]][team_a[k]];

		int B = 0;
		for (int j = 0; j < team_b.size(); j++)
			for (int k = 0; k < team_b.size(); k++)
				B += arr[team_b[j]][team_b[k]];

		if (abs(A - B) < res) res = abs(A - B);
	} while (std::next_permutation(P, P + n));
	printf("%d\n", res);
	return 0;
}