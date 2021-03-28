#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
int size1[501];
bool check[100001];
vector<int> solution(string s) {
	vector<int> ans;
	vector<int> v[501];
	for (int i = 1; i < 100001; i++)check[i] = false;
	int idx = 0;
	int i2 = s.size() - 1;
	int start = 1;
	bool flag = true;
	while(start<i2){
		//temp는 벡터에 넣을 숫자
		int temp = 0;
		while (true) {
			if (s[start] == '}') {
				flag = false;
				v[idx].push_back(temp);
				temp = 0;
				size1[idx] = v[idx].size();
				idx++;
				start++;
				break;
			}
			//숫자를 넣어줘야 할 때는 flag true
			if (s[start] == '{') {
				flag = true;
				start++;
				continue;
			}
			if (s[start] == ',') {
				//flag가 true라면 숫자를 넣어준다.
				if (flag) {
					v[idx].push_back(temp);
					temp = 0;
				}
				start++;
				continue;
			}
			temp *= 10;
			temp += (s[start] - '0');
			start++;
		}
	}
	//for (int i = 0; i < idx; i++) {
	//	for (auto k : v[i])cout << k << ' ';
	//	cout << '\n';
	//}

	//사이즈가 1인 벡터부터 완전탐색
	//숫자를 체크하여 새로 나온것 순서대로 정답 벡터에 넣어준다.
	for (int i = 1; i <= idx; i++) {
		int temp = i;
		for (int j = 0; j < idx; j++) {
			if (size1[j] == i) {
				temp = j;
				break;
			}
		}
		for (auto k : v[temp]) {
			if (check[k] == false) {
				ans.push_back(k);
				check[k] = true;
			}
		}
	}
	return ans;
}
