#include <string>
#include <vector>
#include <iostream>
using namespace std;
int ans,n,t;
vector<int> v;
//완전탐색
void go(int idx, int num) {
	if (idx == n) {
		if (num == t)ans++;
		return;
	}
	go(idx + 1, num + v[idx]);
	go(idx + 1, num - v[idx]);
}
int solution(vector<int> numbers, int target) {
	ans = 0;
	v = numbers;
	n = numbers.size();
	t = target;
	go(0, 0);
	return ans;
}
