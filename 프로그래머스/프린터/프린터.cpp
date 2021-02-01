#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// location�� �߿䵵�� ť�� ������� ���� 
// �߿䵵�� �����Ͽ� ���� ���� ���� �ε����� ���
// �߿䵵�� ��ġ�ϸ� �Ѱ��� ���ְ� ��ġ���� ������ �ٽ� ť�� ����
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
