#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end(), comp);
	sort(B.begin(), B.end(), comp);

	int aIndex = 0;
	int bIndex = 0;

	if (A[A.size() - 1] >= B[0])
		return 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[aIndex] < B[bIndex]) {
			bIndex++;
			answer++;
		}
		aIndex++;
	}

	return answer;
}
