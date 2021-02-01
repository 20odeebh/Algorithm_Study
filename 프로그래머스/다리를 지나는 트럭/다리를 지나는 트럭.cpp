#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
//ť�� Ʈ������ �ִ´�. �̶� �� ���� first�� ����, second�� �� �ð�.
//�� �ð����� ť�� ���ִ� ���Կ� ������ ��� Ʈ���� ���� �� ������ �ְ�,
//���� �� ���ٸ� �ð��� ����Ͽ� �մ���.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int size = truck_weights.size(), idx = 0, qsize = 1,nowweight=truck_weights[0],time=1;
	q.push({ truck_weights[idx++],1 });
	while (true) {
		time++;
		//�տ��ִ� Ʈ���� �ٸ��� �ǳԴٸ�
		if (time - q.front().second >= bridge_length) {
			nowweight -= q.front().first;
			qsize--;
			q.pop();
		}
		//���� Ʈ���� �ִٸ�
		if (idx < size) {
			// �ٸ� ���� ���̿� ���԰� �ִٸ�
			if (qsize < bridge_length && (nowweight + truck_weights[idx]) <= weight) {
				q.push({ truck_weights[idx],time });
				nowweight += truck_weights[idx++];
				qsize++;
			}
			//�ƴ϶�� �ð� �մ���
			else {
				time = q.front().second + bridge_length - 1;
			}
			continue;
		}
		//���� Ʈ���� ���µ� Ʈ���� �ٺ����ٸ� break
		if (q.empty())break;
		time = q.front().second + bridge_length - 1;
	}
	return time;

}