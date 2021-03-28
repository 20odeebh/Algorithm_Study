#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// location과 중요도를 큐에 순서대로 삽입 
// 중요도를 정렬하여 가장 높은 값의 인덱스를 사용
// 중요도가 일치하면 한개씩 빼주고 일치하지 않으면 다시 큐에 삽입
int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;

	int size = priorities.size();
	for (int i = 0; i < size; i++) {
		q.push({ i,priorities[i] });
	}

	sort(priorities.begin(), priorities.end());
	int idx = size - 1;

	while (true) {
		int Nowlocation = q.front().first, Nowpriority = q.front().second;
		q.pop();
		if (Nowpriority == priorities[idx]) {
			answer++;
			idx--;
			if (Nowlocation == location)break;
		}
		else {
			q.push({ Nowlocation,Nowpriority });
		}
	}

	return answer;
}
