// 경로 찾기

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	bool arr[101][101];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %d", &arr[i][j]);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}