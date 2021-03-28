#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
//우선순위큐에 넣어 작은값들을 계산해준다.
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int size = scoville.size();
	for (int i = 0; i < size; i++) {
		pq.push(scoville[i]);
	}
	bool flag = false;
	while (true) {
		if (pq.top() >= K) {
			flag = true;
			break;
		}
		long long a = pq.top();
		pq.pop();
		if (pq.empty())break;
		long long b = pq.top();
		pq.pop();
		pq.push(a + b * 2LL);
		answer++;
	}
	if (flag == false)answer = -1;
	return answer;
}