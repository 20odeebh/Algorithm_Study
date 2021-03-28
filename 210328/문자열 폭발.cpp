#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include<functional>
#include <stack>

using namespace std;
string str, bomb;
deque<char> dq;

// 한번의 문자열 탐색으로 시간을 최소화해야함
// while문으로 반복하면 시간초과
// O(1) 시간에서 문자 삽입/삭제 필요 --> 배열보다는 스택/dq 사용

bool canErase() {
	if (dq.size() < bomb.size())
		return false;

	for (int i = 0; i < bomb.size(); i++) {
		if (bomb[i] != dq[dq.size() - bomb.size()+i])
			return false;
	}

	return true;
}

void Bomb() {
	for (int i = 0; i < str.size(); i++) {
		dq.push_back(str[i]);
		if (dq.back() == bomb.back()) {
			if (canErase()) {
				int cnt = bomb.size();
				while (cnt--)
					dq.pop_back();
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> str >> bomb;


	Bomb();

	if (dq.empty())
		cout << "FRULA";
	else {
		for (auto &k : dq)
			cout << k;
	}
}

