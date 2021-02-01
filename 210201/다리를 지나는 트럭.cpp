#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//��� Ʈ���� �ٸ��� �ǳʴ� �ּ� �ð�
	int answer = 1;
	int limit = 0;
	//Ʈ���� ���� ����, �ð��� ����
	queue<pair<int, int>> wait, bridge;
	for (int i = 0; i < truck_weights.size(); i++)
		wait.push({ truck_weights[i], 0 });
	int w, t;
	//��� ���� Ʈ���̳� �ٸ��� ����ϴ� Ʈ���� ���� ������
	while (!wait.empty() || !bridge.empty()) {
		answer++;
		if (!wait.empty()) {
			w = wait.front().first;
			t = wait.front().second;
			if (limit + w <= weight) {
				wait.pop();
				limit += w;
				bridge.push({ w, t });
			}
		}
		int len = bridge.size();
		for (int i = 0; i < len; i++) {
			w = bridge.front().first;
			t = bridge.front().second;
			bridge.pop();
			if (t + 1 < bridge_length)
				bridge.push({ w, t + 1 });
			//�ٸ����� Ʈ�� ���
			else
				limit -= w;
		}
	}
	return answer;
}

int main()
{
	int len, weight, N;
	scanf("%d", &N);
	vector<int> truck_weight(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &truck_weight[i]);
	scanf("%d %d", &len, &weight);
	solution(len, weight, truck_weight);
	return 0;
}