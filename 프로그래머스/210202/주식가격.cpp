#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> st;
//스택에 담아 top부분을 가장 크게 만들어 인덱스 차이를 계산
vector<int> solution(vector<int> prices) {
	int size = prices.size();
	vector<int> answer(size,0);
	st.push({ prices[0],0 });
	for (int i = 1; i < size; i++) {
		if (st.top().first > prices[i]) {
			while (!st.empty()) {
				if (st.top().first > prices[i]) {
					answer[st.top().second] = i - st.top().second;
					st.pop();
				}
				else break;
			}
		}
		st.push({ prices[i],i });
	}
	while (!st.empty()) {
		answer[st.top().second] = size - 1 - st.top().second;
		st.pop();
	}
	return answer;
}