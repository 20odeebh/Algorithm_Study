#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool IsPossible(vector<int>& stones, int k, int mid)
{
	int cnt = 0, result = 0;
	for (const auto& ston : stones) {
		if (ston < mid)
			cnt++;
		else {
			result = max(cnt, result);
			cnt = 0;
		}
	}
	result = max(cnt, result);
	if (result < k)
		return true;
	return false;
}
int solution(vector<int> stones, int k) {
	int answer = 0;
	int MaxValue = *max_element(stones.begin(), stones.end());
	int l = 0, r = MaxValue, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (IsPossible(stones, k, mid)) {
			l = mid + 1;
			answer = max(mid, answer);
		}
		else
			r = mid - 1;
	}
	return answer;
}