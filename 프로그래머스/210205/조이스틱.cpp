#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//완전탐색
int solution(string name) {
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < name.size(); i++) {
		int temp = name[i] - 'A';
		temp = min(temp,'Z' - name[i] + 1);
		answer += temp;
		if (temp) {
			v.push_back(i);
		}
	}
	if (v.size() == 0) {
		return 0;
	}
	int size = v.size();
	int temp = min(v[size - 1],(int)name.size()-v[0]);
	if (size == 1) {
		temp = min(temp, v[0]);
		temp = min(temp, (int)name.size() - v[0]);
		return answer + temp;
	}
	int size2 = size - 1;
	for (int i = 0; i < size2; i++) {
		int sum = v[i]*2;
		sum += (name.size() - v[i + 1]);
		temp = min(temp,sum);
	}
	for (int i = size2; i > 0; i--) {
		int sum = name.size() - v[i];
		sum *= 2;
		sum += v[i - 1];
		temp = min(temp, sum);
	}
	answer += temp;
	return answer;
}
int main() {
	cout<<solution("BBBBAAAABA")<<'\n';
}