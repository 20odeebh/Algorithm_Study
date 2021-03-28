#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//정렬해서 계산 ( size- 인덱스) 가 인용 a[i]개 이상의 갯수
int solution(vector<int> citations) {
	int answer = 0;
	int size = citations.size();
	sort(citations.begin(), citations.end());
	for (int i = 0; i < size; i++) {
		int l = size - i;
		answer = max(answer, min(l, citations[i]));
	}
	return answer;
}