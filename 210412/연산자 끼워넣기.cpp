#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, MinResult = 1000000002;
int MaxResult = -1000000002;
int arr[11];
vector<int> oper(4, 0);
void dfs(int op_idx, int num_idx, int sum)
{
	if (num_idx == N - 1) {
		MaxResult = max(sum, MaxResult);
		MinResult = min(sum, MinResult);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] <= 0)
			continue;
		if (i == 0) {
			oper[i]--;
			dfs(i, num_idx + 1, sum + arr[num_idx + 1]);
			oper[i]++;
		}
		else if (i == 1) {
			oper[i]--;
			dfs(i, num_idx + 1, sum - arr[num_idx + 1]);
			oper[i]++;
		}
		else if (i == 2) {
			oper[i]--;
			dfs(i, num_idx + 1, sum * arr[num_idx + 1]);
			oper[i]++;
		}
		else if (i == 3) {
			oper[i]--;
			dfs(i, num_idx + 1, sum / arr[num_idx + 1]);
			oper[i]++;
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	dfs(0, 0, arr[0]);
	printf("%d\n%d\n", MaxResult, MinResult);
	return 0;
}