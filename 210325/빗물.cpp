#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>

using namespace std;
int h, w;
int maxh = 0;
int arr[501];
int res = 0;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	// 가장 높은 높이
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
		maxh = max(arr[i], maxh);
	}
	int lefth = arr[0];
	int max_left, max_right;

	for (int i = 0; i < w; i++) {
		if (arr[i] == maxh) {
			max_left = i;
			break;
		}
		if (arr[i] > lefth)
			lefth = arr[i];
		else
			res += (lefth - arr[i]);
	}
	int righth = arr[w - 1];
	for (int i = w - 1; i > 0; i--) {
		if (arr[i] == maxh) {
			max_right = i;
			break;
		}
		if (arr[i] > righth)
			righth = arr[i];
		else
			res += (righth - arr[i]);
	}

	if (max_left != max_right) {
		for (int i = max_left+1; i < max_right; i++) {
			res += (maxh - arr[i]);
		}
	}

	cout << res;

}
