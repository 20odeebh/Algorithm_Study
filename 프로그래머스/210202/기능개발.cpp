#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int psize = progresses.size();
	if (psize == 0)return answer;

	int start = 0,num=0;
	int temp = 100 - progresses[0];
	//시작시간을 처음 작업 완료시간으로 정해놓는다.
	start = temp / speeds[0];
	if (temp % speeds[0])start++;

	//뒤작업이 완료되었으면 num을 증가시켜주면서 contine
	//아니라면 작업시간을 다시 맞춰서 계속 진행
	for (int i = 0; i < psize; i++) {
		int cur_pro = progresses[i] + start * speeds[i];
		if (cur_pro >= 100) {
			num++;
		}
		else {
			answer.push_back(num);
			num = 1;
			temp = 100 - progresses[i];
			start = temp / speeds[i];
			if (temp % speeds[i])start++;
		}
	}
	if (num != 0)answer.push_back(num);
	return answer;
}