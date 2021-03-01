#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
	// std::priority_queue�� �����ϰ�, works�� ���� �۾����� �Űܴ�´�.
	std::priority_queue<int> q(works.begin(), works.end());
	// �۾��ð� n ��ŭ ����, �۾����� �ִ񰪿��� 1�� ����.
	for (int i = 0; i < n; i++) {
		if (q.top() > 0) {
			// ť���� �ִ��� ��������, -1 �ؼ� �ٽ� �ִ´�.
			int tmp = q.top();
			q.pop();
			q.push(tmp - 1);
		}
	}
	// ����������, ���� �۾������� �Ƿε��� ����Ѵ�.
	long long answer = 0;
	while (!q.empty()) {
		answer += (long long)q.top() * (long long)q.top();
		q.pop();
	}
	return answer;
}