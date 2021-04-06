#include <iostream>
#include <vector>
using namespace std;
bool visit[8];
int N, K;
int result = 0;
const int weight = 500;
int arr[8];
bool IsSuccess(vector<int>& picked)
{
	int sum = 0;
	for (int i = 0; i < picked.size(); i++) {
		sum += arr[picked[i]];
		if (K * (i + 1) - sum > 0)
			return false;
	}
	return true;
}
void dfs(vector<int>& picked, int toPick)
{
	if (toPick == 0) {
		if (IsSuccess(picked))
			result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			picked.push_back(i);
			dfs(picked, toPick - 1);
			visit[i] = false;
			picked.pop_back();
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> v;
	dfs(v, N);
	printf("%d\n", result);
	return 0;
}