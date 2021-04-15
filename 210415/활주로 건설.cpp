// 활주로 건설

#include <stdio.h>

int test_case, n, x, res;
int arr[21][41];

int main() {
	//freopen("sample_input.txt", "r", stdin);
	int h, i, j;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf(" %d %d", &n, &x);
		res = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf(" %d", &arr[i][j]);
		for (j = 0; j < n; j++)
			for (i = 0; i < n; i++)
				arr[j][i + n] = arr[i][j];

		for (j = 0; j < n + n; j++) {
			h = 1;
			for (i = 0; i < n - 1; i++) {
				if (arr[i][j] == arr[i + 1][j]) h++;
				else if (arr[i][j] - 1 == arr[i + 1][j] && h >= 0) h = 1 - x;
				else if (arr[i][j] + 1 == arr[i + 1][j] && h >= x) h = 1;
				else break;
			}
			if (i == n - 1 && h >= 0)
				res++;
		}
		printf("#%d %d\n", tc, res);
	}
	return 0;
}