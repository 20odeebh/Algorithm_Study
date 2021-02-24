#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 이분탐색 : 범위가 넓음 
// 주의할 점: right와 left 설정 (right를 정할 때, 최고 시간이 걸릴 때로 설정)

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());
	long long left = 1;
	long long right = (long long)times.back()*n;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long total = 0;
		for (long long i = 0; i<times.size(); i++)
			total += mid / times[i];
		// 현재 시간안에 모두 검사 할 수 없으면 
		if (total<n) {
			left = mid + 1;
		}
		// 현재 시간안에 검사할 수 있으면
		else {
			answer = mid;
			right = mid - 1;
		}
	}
	return answer;
}