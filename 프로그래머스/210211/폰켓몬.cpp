#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool c[200001];
//새로운 번호 나오면 종류 수 증가
//최종 답은 min(종류 수,포켓몬수/2)
int solution(vector<int> nums)
{
	int answer = 0;
	int size = nums.size();
	for (int i = 1; i < 200001; i++) {
		c[i] = false;
	}
	for (int i = 0; i < size; i++) {
		if (c[nums[i]] == false) {
			c[nums[i]] = true;
			answer++;
		}
	}
	answer = min(answer, size / 2);
	return answer;
}