#include <bits/stdc++.h>
using namespace std;
bool c[3001];
//에라토스테네스 체 사용
//완전 탐색
int solution(vector<int> nums) {
	int answer = 0;
	for (int i = 2; i < 3001; i++) {
		if (c[i] == false) {
			for (int j = i * i; j < 3001; j += i) {
				c[j] = true;
			}
		}
	}
	int size = nums.size();
	for (int i = 0; i < size - 2; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			for (int k = j + 1; k < size; k++) {
				if (c[nums[i] + nums[j] + nums[k]] == false)answer++;

			}
		}
	}
	return answer;
}