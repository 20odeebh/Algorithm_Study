// 경사로

#include <stdio.h>

using namespace std;

int main() {
	int n, l, res = 0;
	int arr[101][202];
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);

	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
			arr[j][i + n] = arr[i][j];

	int i, cnt;
	for (int j = 0; j < n + n; j++) {
		cnt = 1;
		for (i = 0; i < n - 1; i++) {
			if (arr[i][j] == arr[i + 1][j]) cnt++;
			else if (arr[i][j] + 1 == arr[i + 1][j] && cnt >= l) cnt = 1;
			else if (arr[i][j] - 1 == arr[i + 1][j] && cnt >= 0) cnt = 1 - l;
			else break;
		}
		if (i == n - 1 && cnt >= 0)	res++;
	}
	printf("%d\n", res);
	return 0;
}