#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
//큐에 트럭들을 넣는다. 이때 들어갈 값은 first에 무게, second에 들어간 시간.
//매 시간마다 큐에 들어가있는 무게와 갯수를 재어 트럭을 넣을 수 있으면 넣고,
//넣을 수 없다면 시간을 계산하여 앞당긴다.
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int size = truck_weights.size(), idx = 0, qsize = 1,nowweight=truck_weights[0],time=1;
	q.push({ truck_weights[idx++],1 });
	while (true) {
		time++;
		//앞에있는 트럭이 다리를 건넜다면
		if (time - q.front().second >= bridge_length) {
			nowweight -= q.front().first;
			qsize--;
			q.pop();
		}
		//넣을 트럭이 있다면
		if (idx < size) {
			// 다리 여분 길이와 무게가 있다면
			if (qsize < bridge_length && (nowweight + truck_weights[idx]) <= weight) {
				q.push({ truck_weights[idx],time });
				nowweight += truck_weights[idx++];
				qsize++;
			}
			//아니라면 시간 앞당기기
			else {
				time = q.front().second + bridge_length - 1;
			}
			continue;
		}
		//넣을 트럭도 없는데 트럭이 다빠졌다면 break
		if (q.empty())break;
		time = q.front().second + bridge_length - 1;
	}
	return time;

}