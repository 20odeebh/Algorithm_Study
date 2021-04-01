/*
접근
dfs, bfs로도 풀 수 있지만 정점의 개수가 적기 때문에 플로이드로도 풀 수 있다.
자기 자신에게 오는 간선이 있다는 것에 유의하여 반복문 내부에 출발, 도착 정점이 같은 경우도 구해주도록 한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 101
int N;
int arr[MAX_SIZE][MAX_SIZE];
void floyd()
{
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}