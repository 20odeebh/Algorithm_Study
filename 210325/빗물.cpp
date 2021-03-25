#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H, W;
vector<int> arr;
int main()
{
	cin >> H >> W;
	arr = vector<int>(W, 0);
	for (int i = 0; i < W; i++)
		cin >> arr[i];
	int answer = 0;
	for (int i = 1; i < W; i++) {
		vector<int>::iterator cur = arr.begin() + i;
		int left = *max_element(arr.begin(), cur);
		int right = *max_element(cur, arr.end());
		int target = min(left, right);
		answer += target - arr[i] > 0 ? target - arr[i] : 0;
	}
	printf("%d\n", answer);
	return 0;
}